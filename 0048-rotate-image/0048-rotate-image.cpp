class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        // Old code

        /*
        int sizeOfMatrix=matrix.size();
        for(int e=0;e<sizeOfMatrix-1;e++){
            for(int f=e+1;f<sizeOfMatrix;f++){
                int g=matrix[e][f];
                matrix[e][f]=matrix[f][e];
                matrix[f][e]=g;
            }
        }
        for(int e=0;e<sizeOfMatrix;e++){
            for(int f=0,g=sizeOfMatrix-1;f<g;f++,g--){
                int h=matrix[e][f];
                matrix[e][f]=matrix[e][g];
                matrix[e][g]=h;
            }
        }
        */


        // Once again

        int n=matrix.size();
        for(int e=0;e<n;e++){
            for(int f=e;f<n;f++){
                if(e==f) continue;
                int g=matrix[e][f];
                matrix[e][f]=matrix[f][e];
                matrix[f][e]=g;
            }
        }
        for(int e=0;e<n;e++){
            for(int f=0,g=n-1;f<g;f++,g--){
                int temp=matrix[e][f];
                matrix[e][f]=matrix[e][g];
                matrix[e][g]=temp;
            }
        }
    }
};