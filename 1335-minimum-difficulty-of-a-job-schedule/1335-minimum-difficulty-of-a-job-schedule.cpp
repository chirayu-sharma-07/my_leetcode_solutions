class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& jobDifficulty, int n, int i, int d){
        if(d==1){
            return *max_element(jobDifficulty.begin()+i, jobDifficulty.end());
        }
        if(dp[i][d] != -1) return dp[i][d];
        
        int res = INT_MAX;
        int curr = INT_MIN;
        for(int j=i; j<=n-d; j++){
            curr = max(curr, jobDifficulty[j]);
            res = min(res, curr + solve(jobDifficulty, n, j+1, d-1));
        }
        return dp[i][d] = res;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        dp.resize(301, vector<int>(11, -1));
        int n = jobDifficulty.size();
        if(n<d) return -1;
        return solve(jobDifficulty, n, 0, d);
    }
};