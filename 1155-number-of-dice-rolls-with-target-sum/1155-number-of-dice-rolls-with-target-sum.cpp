class Solution {
public:
    int memo[31][1001];
    int MOD=1e9+7;
    int myFunction(int n,int k,int target){
        if(target<0) return 0;
        if(n==0) return target==0;
        if(memo[n][target]!=-1) return memo[n][target];
        int result=0;
        for(int e=1;e<=k;e++){
            result=(result+myFunction(n-1,k,target-e))%MOD;
        }
        return memo[n][target]=result;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(memo,-1,sizeof(memo));
        return myFunction(n,k,target);
    }
};