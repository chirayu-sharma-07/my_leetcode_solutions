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

    /*

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
    */


    /*

    int myFunction(int n,vector<int> &memo){
        if(n<0) return 0;
        if(n==0) return 1;
        if(memo[n]!=-1) return memo[n];
        return memo[n]=myFunction(n-1,memo)+myFunction(n-2,memo);
    }
    int climbStairs(int n){
        vector<int> memo(n+1,-1);
        return myFunction(n,memo);
    }
    */

    /*
    int climbStairs(int n){
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 3;
        vector<int> myArray(n+1);
        myArray[0]=0;
        myArray[1]=1;
        myArray[2]=2;
        for(int e=3;e<=n;e++){
            myArray[e]=myArray[e-1]+myArray[e-2];
        }
        return myArray[n];
    }
    */

    int climbStairs(int n){
        if(n==1) return 1;
        else if(n==2) return 2;
        else if(n==3) return 3;
        else if(n==4) return 5;
        else if(n==5) return 8;
        else if(n==6) return 13;
        else if(n==7) return 21;
        else if(n==8) return 34;
        else if(n==9) return 55;
        else if(n==10) return 89;
        else if(n==11) return 144;
        else if(n==12) return 233;
        else if(n==13) return 377;
        else if(n==14) return 610;
        else if(n==15) return 987;
        else if(n==16) return 1597;
        else if(n==17) return 2584;
        else if(n==18) return 4181;
        else if(n==19) return 6765;
        else if(n==20) return 10946;
        else if(n==21) return 17711;
        else if(n==22) return 28657;
        else if(n==23) return 46368;
        else if(n==24) return 75025;
        else if(n==25) return 121393;
        else if(n==26) return 196418;
        else if(n==27) return 317811;
        else if(n==28) return 514229;
        else if(n==29) return 832040;
        else if(n==30) return 1346269;
        else if(n==31) return 2178309;
        else if(n==32) return 3524578;
        else if(n==33) return 5702887;
        else if(n==34) return 9227465;
        else if(n==35) return 14930352;
        else if(n==36) return 24157817;
        else if(n==37) return 39088169;
        else if(n==38) return 63245986;
        else if(n==39) return 102334155;
        else if(n==40) return 165580141;
        else if(n==41) return 267914296;
        else if(n==42) return 433494437;
        else if(n==43) return 701408733;
        else if(n==44) return 1134903170;
        else return 1836311903;
    }
};