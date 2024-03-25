class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        // First approach

        /*
        unordered_map<int,int> myMap;
        vector<int> result;
        for(int &e:nums){
            myMap[e]++;
        }
        for(auto &e:myMap){
            if(e.second>1) result.push_back(e.first);
        }
        return result;
        */

        // Second approach (O(N) runtime complexity and constant extra space)

        int n=nums.size();
        vector<int> result;
        for(int e=0;e<n;e++){
            int num=abs(nums[e])-1;
            if(nums[num]<0) result.push_back(num+1);
            nums[num]=(-1)*nums[num];
        }
        return result;
    }
};