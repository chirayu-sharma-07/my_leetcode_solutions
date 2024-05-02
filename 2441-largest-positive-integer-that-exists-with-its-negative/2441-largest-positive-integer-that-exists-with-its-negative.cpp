class Solution {
public:
    int findMaxK(vector<int>& nums) {

        // Approach one 

        /*
        sort(begin(nums),end(nums));
        int n=nums.size();
        for(int e=0;e<n;e++){
            if(nums[e]<0) nums[e]=nums[e]*(-1);
            else break;
        }
        int e=0;
        n--;
        while(e<n){
            if(nums[e]==nums[n]) return nums[e];
            else if(nums[e]>nums[n]) e++;
            else n--;
        }
        return -1;
        */

        // Approach two

        /*
        unordered_set<int> mySet;
        for(int &e:nums){
            if(e<0 && mySet.find(e)==mySet.end()) mySet.insert(e);
        }
        int largest=INT_MIN;
        for(int &e:nums){
            if(e>0 && e>largest && mySet.find((-1)*e)!=mySet.end()) largest=e;
        }
        return (largest==INT_MIN)?-1:largest;
        */

        // Approach three

        sort(begin(nums),end(nums));
        for(int e=0,f=nums.size()-1;e<f;){
            int g=nums[e]*(-1);
            int h=nums[f];
            if(g==h) return g;
            else if(g>h) e++;
            else f--;
        }
        return -1;
    }
};