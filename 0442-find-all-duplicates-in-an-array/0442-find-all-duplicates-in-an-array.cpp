class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> myMap;
        vector<int> result;
        for(int &e:nums){
            myMap[e]++;
        }
        for(auto &e:myMap){
            if(e.second>1) result.push_back(e.first);
        }
        return result;
    }
};