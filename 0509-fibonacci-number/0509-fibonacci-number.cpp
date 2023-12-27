class Solution {
public:
    int memo[31];
    int myFunction(int n){
        if(memo[n]!=-1) return memo[n];
        return myFunction(n-1)+myFunction(n-2);
    }
    int fib(int n) {
        memset(memo,-1,sizeof(memo));
        memo[0]=0;
        memo[1]=1;
        return myFunction(n);
    }
};