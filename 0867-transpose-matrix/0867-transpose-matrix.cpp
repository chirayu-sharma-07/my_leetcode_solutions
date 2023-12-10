class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>> result(col);
        for(int e=0;e<row;e++){
            for(int f=0;f<col;f++){
                result[f].push_back(matrix[e][f]);
            }
        }
        return result;
    }
};