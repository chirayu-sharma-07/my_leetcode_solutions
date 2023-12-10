class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> result(n,vector<int>(m));
        for(int e=0;e<m;e++){
            for(int f=0;f<n;f++) result[f][e]=matrix[e][f];
        }
        return result;
    }
};