class Solution {
public:

    // Top-Down DP (Recursion + Memoization)

    /*
    int memo[101];
    int myFunction(int e,vector<int> &nums){
        if(e>=nums.size()) return 0;
        if(memo[e]!=-1) return memo[e];
        int steal=nums[e]+myFunction(e+2,nums);
        int skip=myFunction(e+1,nums);
        return memo[e]=(steal<skip)?skip:steal;
    }
    int rob(vector<int>& nums) {

        // First Approach
        // Wrong approach, because it will give Wrong answer error with the testcase - [2,1,1,2] :(

        int result1=0;
        int result2=result1;
        int n=nums.size();
        for(int e=0;e<n;e+=2){
            result1+=nums[e];
        }
        for(int e=1;e<n;e+=2) result2+=nums[e];
        return (result1<result2)?result2:result1;

        // Second approach

        memset(memo,-1,sizeof(memo));
        return myFunction(0,nums);
    }
    */

    // Third approach
    // Bottom-up DP

    /*
    int rob(vector<int> &nums){
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return (nums[0]<nums[1])?nums[1]:nums[0];
        int n=nums.size();
        vector<int> bot_up(n+1,-1);
        bot_up[0]=0;
        bot_up[1]=nums[0];
        for(int e=2;e<=n;e++){
            bot_up[e]=(nums[e-1]+bot_up[e-2]<bot_up[e-1])?bot_up[e-1]:nums[e-1]+bot_up[e-2];
        }
        return bot_up[n];
    }
    */

    // Third approach
    // Bottom-up + constant space 
    // TC - O(n)
    // SC - O(1);

    int rob(vector<int> &nums){
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return (nums[0]<nums[1])?nums[1]:nums[0];
        int n=nums.size();
        int a=0;
        int b=nums[0];
        int c=0;
        for(int e=2;e<=n;e++){
            c=(nums[e-1]+a<b)?b:nums[e-1]+a;
            a=b;
            b=c;
        }
        return c;
    }
};