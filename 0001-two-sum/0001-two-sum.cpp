class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int e=0;e<n;e++){
            if(mp.find(target-nums[e])==mp.end()){
                mp[nums[e]]=e;
            }else return {mp[target-nums[e]],e};
        }
        return {-1,-1};
    }
};