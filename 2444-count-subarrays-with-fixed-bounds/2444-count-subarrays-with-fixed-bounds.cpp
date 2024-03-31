class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        long long result=0;
        int minimum_value_index=-1;
        int maximum_value_index=-1;
        int culprit_value_index=-1;
        for(int e=0;e<n;e++){
            if(nums[e]<minK || nums[e]>maxK)
                culprit_value_index=e;
            
            if(nums[e]==minK)
                minimum_value_index=e;

            if(nums[e]==maxK)
                maximum_value_index=e;

            int minimum_value=min(minimum_value_index,maximum_value_index);
            int temp=minimum_value-culprit_value_index;
            result+=(temp<=0)?0:temp;
        }
        return result;
    }
};