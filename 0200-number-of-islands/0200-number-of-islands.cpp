class Solution {
public:
    int m,n;
    void cover_whole_island(int e,int f,vector<vector<char>> &grid,vector<vector<bool>> &visited){
        if(grid[e][f]=='1' && !visited[e][f]){
            visited[e][f]=!visited[e][f];
            if(e+1<m) cover_whole_island(e+1,f,grid,visited);
            if(f+1<n) cover_whole_island(e,f+1,grid,visited);
            if(e-1>=0) cover_whole_island(e-1,f,grid,visited);
            if(f-1>=0) cover_whole_island(e,f-1,grid,visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int result=0;
        for(int e=0;e<m;e++){
            for(int f=0;f<n;f++){
                if(grid[e][f]=='1' && !visited[e][f]){
                    result++;
                    cover_whole_island(e,f,grid,visited);
                }
            }
        }
        return result;
    }
};