class Solution {
private:
    int memo[101];
    int myFunction(vector<int> &nums,int e,int n){
        if(e>=n) return 0;
        if(memo[e]!=-1) return memo[e];
        int take=nums[e]+myFunction(nums,e+2,n);
        int skip=myFunction(nums,e+1,n);
        return memo[e]=max(take,skip);
    }
public:
    int rob(vector<int>& nums) {
        int nums_size=nums.size();
        memset(memo,-1,sizeof(memo));
        return myFunction(nums,0,nums_size);
    }
};