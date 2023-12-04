class Solution {
public:
    vector<vector<int>> result;
    void twoSum(vector<int> &nums,int n1,int e,int f){
        while(e<f){
            if(nums[e]+nums[f]>n1) f--;
            else if(nums[e]+nums[f]<n1) e++;
            else{
                while(e<f && nums[e]==nums[e+1]) e++;
                while(e<f && nums[f]==nums[f-1]) f--;
                result.push_back({-n1,nums[e],nums[f]});e++;f--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        result.clear();
        sort(begin(nums),end(nums));
        int n=nums.size();
        set<int> mySet;
        int n1;
        for(int e=0;e<n-2;e++){
            if(mySet.find(nums[e])!=mySet.end()) continue;
            mySet.insert(nums[e]);
            n1=-(nums[e]);
            twoSum(nums,n1,e+1,n-1);
        }
        return result;
    }
};