class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result=INT_MIN;
        int sum=0;
        int n=nums.size();
        for(int e=0;e<n;e++){
            sum+=nums[e];
            if(sum>result) result=sum;
            if(sum<0) sum=0;
        }
        return result;
    }
};