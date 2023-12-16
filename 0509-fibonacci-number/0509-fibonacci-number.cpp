class Solution {
public:
    int memo[31];
    Solution(){
        memo[0]=0;
        memo[1]=1;
        for(int e=2;e<31;e++) memo[e]=-1;
    }
    int fib(int n) {
        if(memo[n]!=-1) return memo[n];
        return fib(n-1)+fib(n-2);
    }
};