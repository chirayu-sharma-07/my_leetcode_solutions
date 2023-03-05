class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        if(nums.size()==2){
            if(nums[0]>nums[1]) return 0;
            else return 1;
        }
        for(int e=1;e<nums.size()-1;e++){
            if(nums[e]>nums[e-1] && nums[e]>nums[e+1]) return e;
        }
        if(nums[0]>nums[1]) return 0;
        if(nums[nums.size()-1]>nums[nums.size()-2]) return nums.size()-1;
        return -1;
    }
};