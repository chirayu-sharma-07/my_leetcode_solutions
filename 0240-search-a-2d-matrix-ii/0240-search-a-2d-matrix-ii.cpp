class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Brute force approach
        int m=matrix.size();
        int n=matrix[0].size();
        for(int e=0;e<m;e++){
            for(int f=0;f<n;f++){
                if(matrix[e][f]==target) return true;
            }
        }
        return false;
    }
};