class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       std::sort(nums.begin(),nums.end());
       vector<int> result;
       for(int e=0;e<nums.size()-1;e++){
           if(nums[e]==nums[e+1]){
               result.push_back(nums[e]);
               e++;
           }
       }
       return result;
    }
};