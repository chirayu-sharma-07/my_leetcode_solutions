class Solution {
public:
    int memo[10001];
    int recursiveFunction(int n){
        if(n==0) return 0;
        if(memo[n]!=-1) return memo[n];
        int result=INT_MAX;
        for(int e=1;e*e<=n;e++){
            int sub_result=1+recursiveFunction(n-(e*e));
            result=min(result,sub_result);
        }
        return memo[n]=result;
    }
    int numSquares(int n) {
        memset(memo,-1,sizeof(memo));
        return recursiveFunction(n);
    }
};