class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int> first(m,0);
        vector<int> second(n,0);
        for(int e=0;e<m;e++){
            for(int f=0;f<n;f++){
                if(mat[e][f]==1){
                    first[e]++;
                    second[f]++;
                }
            }
        }
        int result=0;
        for(int e=0;e<m;e++){
            for(int f=0;f<n;f++){
                if(mat[e][f]==1 && first[e]==1 && second[f]==1) result++;
            }
        }
        return result;
    }
};