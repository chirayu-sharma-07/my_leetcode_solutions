class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result=INT_MIN;
        int sub_result=0;
        int n=nums.size();
        for(int e=0;e<n;e++){
            sub_result+=nums[e];
            if(result<sub_result) result=sub_result;
            if(sub_result<0) sub_result=0;
        }
        return result;
    }
};