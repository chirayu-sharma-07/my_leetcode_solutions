class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // brute force approach

        /*
        int n=grid.size();
        int m=grid[0].size();
        int result=0;
        for(int e=0;e<n;e++){
            for(int f=0;f<m;f++){
                if(grid[e][f]<0) result++;
            }
        }
        return result;
        */

        // Second approach

        int n=grid.size()-1;
        int m=grid[0].size()-1;
        int result=0;
        for(;n>=0;n--){
            for(int e=m;e>=0;e--){
                if(grid[n][e]>=0) break;
                result++;
            }
        }
        return result;
    }
};