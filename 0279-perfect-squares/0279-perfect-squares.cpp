class Solution {
public:

    // Recursion + Memoization
    /*
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
    */

    // Second approach
    // Bottom-up DP
    int numSquares(int n){
        vector<int> bot_up(n+1,10001);
        bot_up[0]=0;
        for(int e=1;e<=n;e++){
            for(int f=1;f*f<=e;f++){
                bot_up[e]=min(bot_up[e],1+bot_up[e-f*f]);
            }
        }
        return bot_up[n];
    }
};