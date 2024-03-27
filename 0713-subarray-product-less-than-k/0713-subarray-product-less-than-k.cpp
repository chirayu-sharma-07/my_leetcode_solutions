class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        // Brute force approach

        /*
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
        */

        // Sliding window technique

        int n=nums.size();
        if(k<=1) return 0;
        int result=0;
        for(int e=0,f=0,product=1;f<n;){
            product*=nums[f];
            while(product>=k){
                product/=nums[e];
                e++;
            }
            result+=(f-e+1);
            f++;
        }
        return result;
    }
};