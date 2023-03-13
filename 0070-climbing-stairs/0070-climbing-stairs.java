class Solution {
    private static int myFunction(int n,int[] memoization){
        if(n<=1) return 1;
        if(memoization[n]>0) return memoization[n];
        memoization[n]=(myFunction(n-1,memoization)+myFunction(n-2,memoization));
        return memoization[n];
    }
    public int climbStairs(int n) {
        if(n==1) return 1;
        int[] memoization=new int[n+1];
        return myFunction(n,memoization);
    }
}