class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> myMap;
        int n=nums.size();
        for(int e=0;e<n;e++){
            int num=target-nums[e];
            if(myMap.find(num)==myMap.end()){
                myMap[nums[e]]=e;
            }else{
                return {myMap[num],e};
            }
        }
        return {-1,-1};
    }
};