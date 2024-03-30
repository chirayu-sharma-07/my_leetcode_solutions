class Solution {
public:
    int slidingWindow(vector<int> &nums,int K){
        unordered_map<int,int> myMap;
        int e=0;
        int f=0;
        int result=0;
        int n=nums.size();
        while(f<n){
            myMap[nums[f]]++;
            while(myMap.size()>K){
                myMap[nums[e]]--;
                if(myMap[nums[e]]==0) myMap.erase(nums[e]);
                e++;
            }
            result+=f-e+1;
            f++;
        }
        return result;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        // First approach (TLE)

        /*
        unordered_set<int> mySet;
        int n=nums.size();
        int result=0;
        for(int e=0;e<n;e++){
            for(int f=e,count=0;f<n;f++){
                if(mySet.find(nums[f])==mySet.end()){
                    mySet.insert(nums[f]);
                    count++;
                }
                if(count==k) result++;
                else if(count>k) break;
            }
            mySet.clear();
        }
        return result;
        */

        // Second approach
        
        /*
        int n=nums.size();
        int result=0;
        unordered_set<int> mySet;
        int e=0;
        int f=0;
        while(f<n){
            if(mySet.size()==k) result++;
            if(mySet.find(nums[f])==mySet.end() && mySet.size()<k){
                mySet.insert(nums[f]);
            }else if(mySet.size()==k){

            }
            f++;
        }
        return result;
        */

        return slidingWindow(nums,k)-slidingWindow(nums,k-1);
    }
};