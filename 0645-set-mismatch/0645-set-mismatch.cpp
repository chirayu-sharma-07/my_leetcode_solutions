class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        // Approach one

        /*
        int n=nums.size();
        vector<int> occurances(n+1,0);
        for(int e=0;e<n;e++) occurances[nums[e]]++;
        int a=0;
        int b=0;
        for(int e=1;e<=n;e++){
            if(occurances[e]==2) a=e;
            if(occurances[e]==0) b=e;
        }
        return {a,b};
        */

        // Approach two
        // Using set itself

        int n=nums.size();
        unordered_set<int> mySet;
        int a=0;
        int b=0;
        for(int b=0;b<n;b++){
            if(mySet.find(nums[b])!=mySet.end()) a=nums[b];
            else mySet.insert(nums[b]);
        }
        b=1;
        for(;b<=n;b++){
            if(mySet.find(b)==mySet.end()){
                break;
            }
        }
        return {a,b};
    }
};