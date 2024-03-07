class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int result=INT_MIN;
        int sub_result=0;
        for(int e=0;e<n;e++){
            sub_result=(nums[e]>sub_result+nums[e])?nums[e]:sub_result+nums[e];
            result=(result>sub_result)?result:sub_result;
        }
        return result;
    }
};