class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> um;
        int n=numbers.size();
        for(int e=0;e<n;e++){
            if(um.find(target-numbers[e])==um.end()){
                um[numbers[e]]=e;
            }else return {um[target-numbers[e]]+1,e+1};
        }
        return {-1,-1};
    }
};