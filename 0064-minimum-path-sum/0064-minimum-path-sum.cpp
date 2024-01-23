class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int e=1;e<n;e++) grid[0][e]+=grid[0][e-1];
        for(int e=1;e<m;e++) grid[e][0]+=grid[e-1][0];
        for(int e=1;e<m;e++){
            for(int f=1;f<n;f++){
                grid[e][f]+=min(grid[e-1][f],grid[e][f-1]);
            }
        }
        return grid[m-1][n-1];
    }
};