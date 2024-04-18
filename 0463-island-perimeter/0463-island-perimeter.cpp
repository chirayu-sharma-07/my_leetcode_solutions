class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int answer=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int e=0;e<m;e++){
            for(int f=0;f<n;f++){
                if(grid[e][f]==1){
                    int result=4;
                    if(e+1<m){
                        if(grid[e+1][f]==1) result--;
                    }
                    if(f+1<n){
                        if(grid[e][f+1]==1)  result--;
                    }
                    if(e-1>=0){
                        if(grid[e-1][f]==1) result--;
                    }
                    if(f-1>=0){
                        if(grid[e][f-1]==1) result--;
                    }
                    answer+=result;
                }
            }
        }
        return answer;
    }
};