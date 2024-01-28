class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int result=0;
        unordered_map<int,int> myMap;
        myMap[0]++;
        int sum=0;
        for(int e=0;e<n;e++){
            sum+=nums[e];
            if(myMap.find(sum-k)!=myMap.end()){
                result+=myMap[sum-k];
            }
            myMap[sum]++;
        }
        return result;
    }
};