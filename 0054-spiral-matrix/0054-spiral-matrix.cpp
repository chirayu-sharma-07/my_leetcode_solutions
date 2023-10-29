class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top=0;
        int bottom=matrix.size()-1;
        int left=0;
        int right=matrix[0].size()-1;
        vector<int> result;
        while(top<=bottom && left<=right){
            for(int e=left;e<=right;e++){
                result.push_back(matrix[top][e]);
            }
            top++;
            for(int e=top;e<=bottom;e++){
                result.push_back(matrix[e][right]);
            }
            right--;
            if(top<=bottom){
                for(int e=right;e>=left;e--){
                    result.push_back(matrix[bottom][e]);
                }
                bottom--;
            }
            if(left<=right){
                for(int e=bottom;e>=top;e--){
                    result.push_back(matrix[e][left]);
                }
                left++;
            }
        }
        return result;
    }
};