class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> myMap;
        int result=0;
        int sum=0;
        myMap[sum]++;
        for(auto &e:nums){
            sum+=e;
            if(myMap.find(sum-k)!=myMap.end()){
                result+=myMap[sum-k];
            }
            myMap[sum]++;
        }
        return result;
    }
};