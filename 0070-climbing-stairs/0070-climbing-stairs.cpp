class Solution {
public:
    int myFunction(int n,vector<int> &memo){
        if(n<0) return 0;
        if(n==0) return memo[n]=1;
        if(memo[n]!=-1) return memo[n];
        int result=myFunction(n-1,memo);
        result+=myFunction(n-2,memo);
        return memo[n]=result;
    }
    int climbStairs(int n) {
        vector<int> memo(n+1,-1);
        return myFunction(n,memo);
    }
};