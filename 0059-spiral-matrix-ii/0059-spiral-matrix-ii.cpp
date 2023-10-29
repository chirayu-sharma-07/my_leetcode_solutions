class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result;
        result.resize(n);
        for(int e=0;e<n;e++){
            result[e].reserve(n);
        }
        int matrix[n][n];
        int top=0;
        int bottom=n-1;
        int left=0;
        int right=bottom;
        int num=1;
        while(top<=bottom && left<=right){
            for(int e=left;e<=right;e++){
                matrix[top][e]=num;
                num++;
            }
            top++;
            for(int e=top;e<=bottom;e++){
                matrix[e][right]=num;
                num++;
            }
            right--;
            for(int e=right;e>=left;e--){
                matrix[bottom][e]=num;
                num++;
            }
            bottom--;
            for(int e=bottom;e>=top;e--){
                matrix[e][left]=num;
                num++;
            }
            left++;
        }
        for(int e=0;e<n;e++){
            for(int f=0;f<n;f++){
                result[e].push_back(matrix[e][f]);
            }
        }
        return result;
    }
};