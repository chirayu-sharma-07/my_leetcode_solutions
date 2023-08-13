class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<bool> dp={true,false,nums[0]==nums[1]};
        for(int e=2;e<n;e++){
            bool toBeFilled=false;
            if(nums[e]==nums[e-1] && dp[1]) toBeFilled=true;
            else if(nums[e]==nums[e-1] && nums[e-1]==nums[e-2] && dp[0]) toBeFilled=true;
            else if(nums[e]-nums[e-1]==1 && nums[e-1]-nums[e-2]==1 && dp[0]) toBeFilled=true;
            dp[0]=dp[1];
            dp[1]=dp[2];
            dp[2]=toBeFilled;
        }
        return dp[2];
    }
};