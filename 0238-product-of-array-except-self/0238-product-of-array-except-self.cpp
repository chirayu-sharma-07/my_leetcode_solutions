class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // First approach

        /*
        int zero_count=0;
        int n=nums.size();
        int zero_index=-1;
        for(int e=0;e<n;e++){
            if(nums[e]==0){
                if(zero_count==0){
                    zero_index=e;
                }
                if(zero_count==2) break;
                zero_count++;
            }
        }
        if(zero_count==2){
            for(int e=0;e<n;e++) nums[e]=0;
            return nums;
        }else if(zero_count==1){
            long long product=1;
            for(int e=0;e<n;e++){
                if(e==zero_index) continue;
                product*=nums[e];
            }
            for(int e=0;e<n;e++) nums[e]=0;
            nums[zero_index]=product;
            return nums;
        }else{
            long long product=1;
            for(int &e:nums) product*=e;
            for(int e=0;e<n;e++){
                nums[e]=product/nums[e];
            }
            return nums;
        }
        return nums;
        */

        // Second approach (Using O(N) extra space)

        int n=nums.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0]=right[n-1]=1;
        for(int e=1;e<n;e++){
            left[e]=left[e-1]*nums[e-1];
        }
        for(int f=n-2;f>=0;f--){
            right[f]=right[f+1]*nums[f+1];
        }
        for(int e=0;e<n;e++){
            left[e]=left[e]*right[e];
        }
        return left;
    }
};