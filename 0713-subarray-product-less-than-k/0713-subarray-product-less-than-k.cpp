class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int result=0;
        int n=nums.size();
        for(int e=0;e<n;e++){
            if(nums[e]<k) result++;
            long long product=nums[e];
            for(int f=e+1;f<n;f++){
                product*=nums[f];
                if(product<k) result++;
                else break;
            }
        }
        return result;
    }
};