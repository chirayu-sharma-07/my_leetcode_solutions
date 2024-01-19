class Solution {
public:

    // Approach one
    // Recursion + Memoization

    /*
    int memo[101][101];
    int N=0;
    int myFunction(vector<vector<int>> &matrix,int row,int col){
        if(row==N-1){
            return matrix[row][col];
        }
        if(memo[row][col]!=-1) return memo[row][col];
        int sum=matrix[row][col];
        int result=INT_MAX;
        if(row+1<N && col-1>=0) result=min(result,sum+myFunction(matrix,row+1,col-1));
        if(row+1<N) result=min(result,sum+myFunction(matrix,row+1,col));
        if(row+1<N && col+1<N) result=min(result,sum+myFunction(matrix,row+1,col+1));
        return memo[row][col]=result;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        N=matrix.size();
        memset(memo,-1,sizeof(memo));
        int result=INT_MAX;
        for(int e=0;e<N;e++){
            result=min(result,myFunction(matrix,0,e));
        }
        return result;
    }
    */

    // Second approach
    // Bottom Up DP

    int minFallingPathSum(vector<vector<int>> &matrix){
        int n=matrix.size();
        int m=n-2;
        while(m>=0){
            for(int e=0;e<n;e++){
                int minimum=INT_MAX;
                if(e-1>=0) minimum=min(minimum,matrix[m+1][e-1]);
                minimum=min(minimum,matrix[m+1][e]);
                if(e+1<n) minimum=min(minimum,matrix[m+1][e+1]);
                matrix[m][e]+=minimum;
            }
            m--;
        }
        int result=INT_MAX;
        for(int e=0;e<n;e++){
            result=min(result,matrix[0][e]);
        }
        return result;
    }
};