class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::sort(nums.begin(),nums.end());
        if(k==nums.size()) return nums[0];
        if(k==1) return nums[nums.size()-1];
        k--;
        int e=nums.size()-1;
        while(k!=0 && e>0){
            k--;
            e--;
        }
        /*
        while(k!=0 && e>0){
            while(e>0 && nums[e-1]==nums[e]) e--;
            k--;
            e--;
        }
        */
        return nums[e];
    }
};