class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        for(int e=0,f=0;e<n && f<m;){
            if(nums1[e]==nums2[f]) return nums1[e];
            if(nums1[e]<nums2[f]) e++;
            else f++;
        }
        return -1;
    }
};