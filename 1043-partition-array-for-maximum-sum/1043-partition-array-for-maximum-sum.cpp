class Solution {
public:
    int N=0;
    int memo[501];
    int solve(int e,vector<int> &arr,int k){
        if(e>=N) return 0;
        if(memo[e]!=-1) return memo[e];
        int result=0;
        int max_element=INT_MIN;
        for(int f=e;f<N && f-e+1<=k;f++){
            max_element=max(max_element,arr[f]);
            result=max(result,((f-e+1)*max_element)+solve(f+1,arr,k));
        }
        return memo[e]=result;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        N=arr.size();
        memset(memo,-1,sizeof(memo));
        return solve(0,arr,k);
    }
};