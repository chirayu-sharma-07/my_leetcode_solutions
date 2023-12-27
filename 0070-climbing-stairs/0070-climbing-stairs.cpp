class Solution {
public:

    // First Approach
    // Recursion_Memoization

    /*
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
    */

    // Second approach
    // Bottom-up DP
    // TC - O(n)
    // SC - O(n)
    
    /*
    int climbStairs(int n){
        if(n==1) return 1;
        if(n==2 || n==3) return (n==2)?2:3;
        vector<int> bot_up(n+1,-1);
        bot_up[0]=0;
        bot_up[1]=1;
        bot_up[2]=2;
        bot_up[3]=3;
        for(int e=4;e<=n;e++){
            bot_up[e]=bot_up[e-1]+bot_up[e-2];
        }
        return bot_up[n];
    }
    */

    // Third approach
    // Most optimized
    // TC - O(n)
    // SC - O(1)

    int climbStairs(int n){
        if(n==1) return 1;
        if(n==2 || n==3) return (n==2)?2:3;
        int a=2;
        int b=3;
        int c=0;
        for(int e=4;e<=n;e++){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};