class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> mySet;
        vector<int> result;
        int n=nums1.size();
        for(int e=0;e<n;e++){
            if(mySet.find(nums1[e])==mySet.end()){
                mySet.insert(nums1[e]);
            }
        }
        n=nums2.size();
        for(int e=0;e<n;e++){
            if(mySet.find(nums2[e])!=mySet.end()){
                result.push_back(nums2[e]);
                mySet.erase(nums2[e]);
            }
        }
        return result;
    }
};