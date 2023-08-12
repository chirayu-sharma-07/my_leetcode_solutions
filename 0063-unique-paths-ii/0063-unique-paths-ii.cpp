class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows=obstacleGrid.size();
        int columns=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[rows-1][columns-1]==1) return 0;
        vector<vector<int>> dp(rows,vector<int>(columns,0));
        dp[0][0]=1;
        for(int e=0;e<rows;e++){
            for(int f=0;f<columns;f++){
                if(e==0 && f==0) continue;
                if(obstacleGrid[e][f]==0){
                    int i=0;
                    int j=0;
                    if(e-1>=0) i=dp[e-1][f];
                    if(f-1>=0) j=dp[e][f-1];
                    dp[e][f]=i+j;
                }
            }
        }
        return dp[rows-1][columns-1];
    }
};

// MY TIME LIMIT EXCEEDED CODE :(
/*
class Solution {
private:
    int result;
    int rows;
    int columns;
public:
    void letsHelpRobot(int e,int f,vector<vector<int>>& obstacleGrid){
        if(e==rows-1 && f==columns-1){
            result++;
            return;
        }
        if(obstacleGrid[e][f]==1) return;
        if(e<rows-1){
            letsHelpRobot(e+1,f,obstacleGrid);
        }
        if(f<columns-1){
            letsHelpRobot(e,f+1,obstacleGrid);
        }
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        result=0;
        rows=obstacleGrid.size();
        columns=obstacleGrid[0].size();
        if(obstacleGrid[rows-1][columns-1]==1) return 0;
        letsHelpRobot(0,0,obstacleGrid);
        return result;
    }
};
*/