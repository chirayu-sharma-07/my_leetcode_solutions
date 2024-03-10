class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // First approach

        /*
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
        */

        // Second approach

        vector<int> first_temp;
        vector<int> second_temp;
        int n=nums1.size();
        int m=nums2.size();
        sort(begin(nums1),end(nums1));
        sort(begin(nums2),end(nums2));
        for(int e=0;e<n;){
            int num=nums1[e];
            while(e<n && nums1[e]==num) e++;
            first_temp.push_back(num);
        }
        for(int e=0;e<m;){
            int num=nums2[e];
            while(e<m && nums2[e]==num) e++;
            second_temp.push_back(num);
        }
        vector<int> result;
        n=first_temp.size();
        m=second_temp.size();
        for(int e=0,f=0;e<n && f<m;){
            if(first_temp[e]==second_temp[f]){
                result.push_back(second_temp[f]);
                e++;
                f++;
            }else if(first_temp[e]<second_temp[f]){
                e++;
            }else f++;
        }
        return result;
    }
};