class Solution {
public:

    // DFS code
    // Gave TLE

    /*
    int M,N;
    int MOD=1000000007;
    int DFS(int e,int f,int moves){
        if(e<0 || f<0 || e==M || f==N) return 1;
        if(moves<=0) return 0;
        return (DFS(e+1,f,moves-1)+DFS(e,f+1,moves-1)+DFS(e-1,f,moves-1)+DFS(e,f-1,moves-1))%MOD;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        M=m;
        N=n;
        return DFS(startRow,startColumn,maxMove);
    }
    */

    int M,N;
    int memo[51][51][51];
    int MOD=1e9+7;
    vector<vector<int>> vec{{0,1},{1,0},{0,-1},{-1,0}};
    int DFS(int e,int f,int moves){
        if(e<0 || f<0 || e==M || f==N) return 1;
        if(moves==0) return 0;
        if(memo[e][f][moves]!=-1) return memo[e][f][moves];
        int result=0;
        for(vector<int> &v:vec){
            int row=e+v[0];
            int col=f+v[1];
            result=(result+DFS(row,col,moves-1))%MOD;
        }
        return memo[e][f][moves]=result;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        M=m;
        N=n;
        memset(memo,-1,sizeof(memo));
        return DFS(startRow,startColumn,maxMove);
    }
};