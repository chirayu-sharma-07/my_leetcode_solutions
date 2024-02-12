class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // Brute force approach

        /*
        int n=nums.size();
        unordered_map<int,int> myMap;
        for(int e=0;e<n;e++){
            myMap[nums[e]]++;
        }
        n/=2;
        for(auto &e:myMap){
            if(e.second>n) return e.first;
        }
        return -1;
        */

        // Optimized approach

        sort(begin(nums),end(nums));
        int n=nums.size();
        for(int e=0;e<n;e++){
            int num=nums[e];
            int f=e;
            while(f<n && nums[f]==num) f++;
            f--;
            if((f-e)+1>n/2) return num;
            else{
                e=f;
            }
        }
        return -1;
    }
};