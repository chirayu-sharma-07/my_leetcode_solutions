class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> myMap;
        myMap[0]=-1;
        int sum=0;
        int result=0;
        for(int e=0;e<n;e++){
            sum+=(nums[e]==1)?1:-1;
            if(myMap.find(sum)!=myMap.end()){
                result=max(result,e-myMap[sum]);
            }else myMap[sum]=e;
        }
        return result;
    }
};