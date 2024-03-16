class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
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
    }
};