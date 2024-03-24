class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> myMap;
        for(int &e:nums){
            myMap[e]++;
        }
        for(auto &e:myMap){
            if(e.second>1) return e.first;
        }
        return 0;
    }
};