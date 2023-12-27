class Solution {
public:
    
    // First approach
    // Recursion + Memoization
    
    int memo[101];
    int myFunction(int e,int n,vector<int> &nums){
        if(e>=n) return 0;
        if(memo[e]!=-1) return memo[e];
        int steal=nums[e]+myFunction(e+2,n,nums);
        int skip=myFunction(e+1,n,nums);
        return memo[e]=(steal<skip)?skip:steal;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        memset(memo,-1,sizeof(memo));
        int include_first_house=myFunction(0,nums.size()-1,nums);
        memset(memo,-1,sizeof(memo));
        int skip_first_house=myFunction(1,nums.size(),nums);
        return (include_first_house<skip_first_house)?skip_first_house:include_first_house;
    }
};