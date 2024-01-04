class Solution {
public:
    int m=0;
    int n=0;
    void recursiveFunction(int e,int f,vector<vector<char>>& grid,vector<vector<bool>> &flag_matrix){
        flag_matrix[e][f]=true;
        if(e>0 && grid[e-1][f]=='1' && flag_matrix[e-1][f]==false){
            recursiveFunction(e-1,f,grid,flag_matrix);
        }
        if(f>0 && grid[e][f-1]=='1' && flag_matrix[e][f-1]==false){
            recursiveFunction(e,f-1,grid,flag_matrix);
        }
        if(e<m-1 && grid[e+1][f]=='1' && flag_matrix[e+1][f]==false){
            recursiveFunction(e+1,f,grid,flag_matrix);
        }
        if(f<n-1 && grid[e][f+1]=='1' && flag_matrix[e][f+1]==false){
            recursiveFunction(e,f+1,grid,flag_matrix);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
       m=grid.size();
       n=grid[0].size();
       vector<vector<bool>> flag_matrix(m,vector<bool>(n,false));
       int result=0;
       for(int e=0;e<m;e++){
           for(int f=0;f<n;f++){
               if(flag_matrix[e][f]==false && grid[e][f]=='1'){
                   result++;
                   recursiveFunction(e,f,grid,flag_matrix);
               }
           }
       }
       return result;
    }
};