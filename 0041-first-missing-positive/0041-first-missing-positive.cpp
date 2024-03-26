class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        // First approach

        /*
        unordered_set<int> mySet;
        for(int &e:nums){
            if(e>0){
                if(mySet.find(e)==mySet.end()){
                    mySet.insert(e);
                }
            }
        }
        int e=1;
        while(true){
            if(mySet.find(e)==mySet.end()) return e;
            e++;
        }
        return 1;
        */

        // Second approach (Taking O(N) extra space)

        int n=nums.size();
        vector<bool> vec(n+1,false);
        for(int &e:nums){
            if(e<1 || e>n) continue;
            vec[e]=true;
        }
        for(int e=1;e<=n;e++){
            if(!vec[e]) return e;
        }
        return n+1;
    }
};