class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // First approach

        /*
        int rowCount=matrix.size();
        int columnCount=matrix[0].size();
        if(matrix[0][0]>target || target>matrix[rowCount-1][columnCount-1]) return false;
        int row=0;
        while(row<rowCount-1){
            if(matrix[row][0]==target) return true;
            if(matrix[row][0]<target && matrix[row+1][0]>target) break;
            row++;
        }
        columnCount--;
        for(int column=0;column<=columnCount;){
            int mid=column+(columnCount-column)/2;
            if(matrix[row][mid]==target) return true;
            if(matrix[row][mid]<target) column=mid+1;
            else columnCount=mid-1;
        }
        return false;
        */

    int m=matrix.size();
    int n=matrix[0].size();
    int e=m-1;
    while(e>=0 && matrix[e][n-1]>=target) e--;
    e++;
    if(e==m) return false;
    int left=0;
    int right=n-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(matrix[e][mid]==target) return true;
        if(matrix[e][mid]<target){
            left=mid+1;
        }else right=mid-1;
    }
    return false;
    }
};