class Solution {
public:
    /*
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Brute force approach
        /*
        int m=matrix.size();
        int n=matrix[0].size();
        for(int e=0;e<m;e++){
            for(int f=0;f<n;f++){
                if(matrix[e][f]==target) return true;
            }
        }
        return false;
        */

        // Second approach

        /*
        int m=matrix.size();
        int n=matrix[0].size();
        int e=0;
        int f=0;
        while(true){
            if(e<n){
                for(int i=e;i<n;i++){
                    if(matrix[e][i]>target) break;
                    if(matrix[e][i]==target) return true;
                }
                e++;
            }
            if(f<m){
                for(int i=f;i<m;i++){
                    if(matrix[i][f]>target) break;
                    if(matrix[i][f]==target) return true;
                }
                f++;
            }
            if(e==n || f==m) break;
        }
        return false;
        }
    }
    */

    // Third approach

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int e=0;
        int f=n-1;
        while(e<m && f>=0){
            if(matrix[e][f]==target) return true;
            if(matrix[e][f]>target) f--;
            else e++;
        }
        return false;
    }
};