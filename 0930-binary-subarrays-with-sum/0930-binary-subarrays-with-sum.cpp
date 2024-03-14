class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        // Brute force approach
        // Gave TLE

        /*
        int result=0;
        int n=nums.size();
        for(int e=0;e<n;e++){
            int sum=0;
            for(int f=e;f<n;f++){
                sum+=nums[f];
                if(sum==goal) result++;
            }
        }
        return result;
        */

        // Second approach (using hashmap)

        unordered_map<int,int> myMap;
        myMap[0]=1;
        int n=nums.size();
        int result=0;
        int sum=0;
        for(int e=0;e<n;e++){
            sum+=nums[e];
            if(myMap.find(sum-goal)!=myMap.end()){
                result+=myMap[sum-goal];
            }
            myMap[sum]++;
        }
        return result;
    }
};