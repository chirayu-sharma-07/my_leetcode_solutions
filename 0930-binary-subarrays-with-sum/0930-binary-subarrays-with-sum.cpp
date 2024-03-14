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

        /*
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
        */

        /*
        unordered_map<int,int> myMap;
        myMap[0]=1;
        int sum=0;
        int result=0;
        for(int &e:nums){
            sum+=e;
            if(myMap.find(sum-goal)!=myMap.end()){
                result+=myMap[sum-goal];
            }
            myMap[sum]++;
        }
        return result;
        */

        // Third approach (Sliding window)

        int n=nums.size();
        int e=0;
        int f=0;
        int result=0;
        int sum=0;
        int zero_count=0;
        while(f<n){
            sum+=nums[f];
            while(e<f && (nums[e]==0 || sum>goal)){
                if(nums[e]==0){
                    zero_count++;
                }else zero_count=0;
                sum-=nums[e];
                e++;
            }
            if(sum==goal) result+=1+zero_count;
            f++;
        }
        return result;
    }
};