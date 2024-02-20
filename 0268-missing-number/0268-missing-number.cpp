class Solution {
public:
    int missingNumber(vector<int>& nums) {

        // Noob approach
        
        unordered_set<int> mySet;
        int n=nums.size();
        for(int e=0;e<n;e++){
            mySet.insert(nums[e]);
        }
        n++;
        while(n--){
            if(mySet.find(n)==mySet.end()) return n;
        }
        return 0;
    }
};