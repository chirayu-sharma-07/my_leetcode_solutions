class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> myMap;
        for(int e=0;e<n;e++){
            myMap[nums[e]]++;
        }
        n/=2;
        for(auto &e:myMap){
            if(e.second>n) return e.first;
        }
        return -1;
    }
};