class Solution {
public:
    int memo[101];
    int myFunction(int e,int n,vector<int> &nums){
        if(e>=n) return 0;
        if(memo[e]!=-1) return memo[e];
        int steal=nums[e]+myFunction(e+2,n,nums);
        int skip=myFunction(e+1,n,nums);
        return memo[e]=(steal>skip)?steal:skip;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return (nums[0]<nums[1])?nums[1]:nums[0];
        memset(memo,-1,sizeof(memo));
        int include_first_house=myFunction(0,n-1,nums);
        memset(memo,-1,sizeof(memo));
        int skip_first_house=myFunction(1,n,nums);
        return (include_first_house<skip_first_house)?skip_first_house:include_first_house;
    }
};