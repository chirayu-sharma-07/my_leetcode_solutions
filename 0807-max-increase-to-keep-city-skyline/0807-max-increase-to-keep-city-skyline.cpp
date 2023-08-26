class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int rows=grid.size();
        int rowsMax[rows];
        int colsMax[rows];
        for(int e=0;e<rows;e++){
            int max1=-1;
            int max2=-1;
            for(int f=0;f<rows;f++){
                if(grid[e][f]>max1) max1=grid[e][f];
                if(grid[f][e]>max2) max2=grid[f][e];
            }
            rowsMax[e]=max1;
            colsMax[e]=max2;
        }
        int result=0;
        for(int e=0;e<rows;e++){
            for(int f=0;f<rows;f++){
                if(grid[e][f]<rowsMax[e] && grid[e][f]<colsMax[f]){
                    result+=(rowsMax[e]>colsMax[f])?colsMax[f]-grid[e][f]:rowsMax[e]-grid[e][f];
                }
            }
        }
        return result;
    }
};