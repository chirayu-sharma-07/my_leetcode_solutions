class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
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
    }
};