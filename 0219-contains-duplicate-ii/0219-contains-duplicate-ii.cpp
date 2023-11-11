class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k==0) return false;
        set<int> mySet;
        int array_size=nums.size();
        for(int e=0,f=0;f<array_size;){
            if((f-e)>k){
                mySet.erase(nums[e]);
                e++;
            }
            if(mySet.find(nums[f])!=mySet.end()) return true;
            mySet.insert(nums[f]);
            f++;
        }
        return false;
    }
};