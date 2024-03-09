class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        // First approach

        /*
        int n=nums1.size();
        int m=nums2.size();
        for(int e=0,f=0;e<n && f<m;){
            if(nums1[e]==nums2[f]) return nums1[e];
            if(nums1[e]<nums2[f]) e++;
            else f++;
        }
        return -1;
        */

        // Second approach

        set<int> mySet;
        int n=nums1.size();
        int m=nums2.size();
        for(int e=0;e<n;){
            int num=nums1[e];
            mySet.insert(num);
            while(e<n && nums1[e]==num) e++;
        }
        for(int e=0;e<m;){
            int num=nums2[e];
            if(mySet.find(num)!=mySet.end()) return num;
            while(e<m && nums2[e]==num) e++;
        }
        return -1;
    }
};