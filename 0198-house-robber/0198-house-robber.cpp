class Solution {
public:
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

        /*
        int result1=0;
        int result2=result1;
        int n=nums.size();
        for(int e=0;e<n;e+=2){
            result1+=nums[e];
        }
        for(int e=1;e<n;e+=2) result2+=nums[e];
        return (result1<result2)?result2:result1;
        */

        // Second approach

        memset(memo,-1,sizeof(memo));
        return myFunction(0,nums);
    }
};