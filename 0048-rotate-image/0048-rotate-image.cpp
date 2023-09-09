class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int dummy[n][n];
        int e,f,g;
        for(e=0,g=n-1;e<n;e++,g--){
            for(f=0;f<n;f++){
                dummy[f][g]=matrix[e][f];
            }
        }
        for(e=0;e<n;e++){
            for(f=0;f<n;f++){
                matrix[e][f]=dummy[e][f];
            }
        }
    }
};