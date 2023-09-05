class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int x=0;
        for(int e=0;e<nums.size();e++){
            x=x^nums[e];
        }
        return x;
    }
};