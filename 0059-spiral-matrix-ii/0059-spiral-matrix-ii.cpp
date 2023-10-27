class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top=0;
        int bottom=n-1;
        int left=0;
        int right=bottom;
        vector<vector<int>> result;
        result.resize(n);
        for(int e=0;e<n;e++){
            result[e].reserve(n);
        }
        int matrix[n][n];
        for(int e=0;e<n;e++){
            for(int f=0;f<n;f++){
                matrix[e][f]=0;
            }
        }
        for(int e=1;top<=bottom && left<=right;){
            for(int f=left;f<=right;f++){
                matrix[top][f]=e;
                e++;
            }
            top++;
            for(int f=top;f<=bottom;f++){
                matrix[f][right]=e;
                e++;
            }
            right--;
            for(int f=right;f>=left;f--){
                matrix[bottom][f]=e;
                e++;
            }
            bottom--;
            for(int f=bottom;f>=top;f--){
                matrix[f][left]=e;
                e++;
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