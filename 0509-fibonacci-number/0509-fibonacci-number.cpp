class Solution {
public:

    //First approach
    // Recursion+Memoization
    // TC - O(2^n) very bad solution if memoization is not applied
    // SC - O(n) for memoization array
    /*
    int memo[31];
    int myFunction(int n){
        if(memo[n]!=-1) return memo[n];
        return memo[n]=myFunction(n-1)+myFunction(n-2);
    }
    int fib(int n) {
        memset(memo,-1,sizeof(memo));
        memo[0]=0;
        memo[1]=1;
        return myFunction(n);
    }
    */

    //Second Approach
    // Bottom-up approach
    // TC - O(n)
    // SC - O(n)

    int fib(int n){
        if(n<=1) return n;
        vector<int> bot_up(n+1,-1);
        bot_up[0]=0;
        bot_up[1]=1;
        for(int e=2;e<=n;e++){
            bot_up[e]=bot_up[e-1]+bot_up[e-2];
        }
        return bot_up[n];
    }
};