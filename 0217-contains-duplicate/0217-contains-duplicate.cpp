class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        for(int e=0;e<nums.size()-1;e++){
            if(nums[e]==nums[e+1]) return true;
        }
        return false;
    }
};