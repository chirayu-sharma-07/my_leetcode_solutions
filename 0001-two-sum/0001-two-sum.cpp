class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> myMap;
        int n=nums.size();
        for(int e=0;e<n;e++){
            if(myMap.find(target-nums[e])==myMap.end()){
                myMap[nums[e]]=e;
            }else{
                return {myMap[target-nums[e]],e};
            }
        }
        return {-1,-1};
    }
};