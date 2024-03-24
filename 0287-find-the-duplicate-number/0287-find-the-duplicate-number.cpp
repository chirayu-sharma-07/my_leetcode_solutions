class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // First approach

        /*
        unordered_map<int,int> myMap;
        for(int &e:nums){
            myMap[e]++;
        }
        for(auto &e:myMap){
            if(e.second>1) return e.first;
        }
        return 0;
        */

        // Second approach
        
        sort(begin(nums),end(nums));
        int n=nums.size();
        for(int e=0;e<n-1;e++){
            if(nums[e]==nums[e+1]) return nums[e];
        }
        return 0;
    }
};