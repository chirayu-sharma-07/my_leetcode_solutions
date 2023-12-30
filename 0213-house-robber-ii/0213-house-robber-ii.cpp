class Solution {
public:

    // First approach
    // Recursion + memoization

    /*
    int memo[101];
    int myFunction(int e,int n,vector<int> &nums){
        if(e>=n) return 0;
        if(memo[e]!=-1) return memo[e];
        int steal=nums[e]+myFunction(e+2,n,nums);
        int skip=myFunction(e+1,n,nums);
        return memo[e]=(steal>skip)?steal:skip;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return (nums[0]<nums[1])?nums[1]:nums[0];
        memset(memo,-1,sizeof(memo));
        int include_first_house=myFunction(0,n-1,nums);
        memset(memo,-1,sizeof(memo));
        int skip_first_house=myFunction(1,n,nums);
        return (include_first_house<skip_first_house)?skip_first_house:include_first_house;
    }
    */

    // Second approach
    // Bottom up
    // TC - O(n)
    // SC - O(n)
    
    int rob(vector<int> &nums){
        int n=nums.size();
        if(n==1 || n==2){
            return (n==1)?nums[0]:((nums[0]<nums[1])?nums[1]:nums[0]);
        }
        vector<int> bot_up(n+1,0);
        for(int e=1;e<n;e++){
            int steal=nums[e-1]+((e>=2)?bot_up[e-2]:0);
            int skip=bot_up[e-1];
            bot_up[e]=(steal<skip)?skip:steal;
        }
        int sub_result=bot_up[n-1];
        bot_up.clear();
        bot_up[0]=0;
        bot_up[1]=0;
        for(int e=2;e<=n;e++){
            int steal=nums[e-1]+bot_up[e-2];
            int skip=bot_up[e-1];
            bot_up[e]=(steal<skip)?skip:steal;
        }
        return (bot_up[n]<sub_result)?sub_result:bot_up[n];
    }
};