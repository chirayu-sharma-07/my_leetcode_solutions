class Solution {
private:
    bool myFunction(vector<vector<int>> &mat,int e,int f,int m,int n){
        for(int i=0;i<m;i++){
            if(mat[i][f]!=0){
                if(i!=e) return false;
            }
        }
        for(int i=0;i<n;i++){
            if(mat[e][i]!=0){
                if(f!=i) return false;
            }
        }
        return true;
    }
public:
    int numSpecial(vector<vector<int>>& mat) {
        int result=0;
        int m=mat.size();
        int n=mat[0].size();
        for(int e=0;e<m;e++){
            for(int f=0;f<n;f++){
                if(mat[e][f]==1){
                    if(myFunction(mat,e,f,m,n)) result++;
                }
            }
        }
        return result;
    }
};