class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> myMap;
        int result=0;
        int e=0;
        int f=0;
        while(f<n){
            if(myMap[nums[f]]<k){
                myMap[nums[f]]++;
                f++;
            }else{
                myMap[nums[e]]--;
                e++;
            }
            result=max(result,f-e);
        }
        return result;
    }
};