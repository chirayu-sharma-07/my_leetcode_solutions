class Solution {
private:
    void setKaro(vector<vector<int>>& matrix,int e,int f){
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][f]!=0) matrix[i][f]=0;
        }
        for(int i=0;i<m;i++){
            if(matrix[e][i]!=0) matrix[e][i]=0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> x;
        for(int e=0;e<matrix.size();e++){
            for(int f=0;f<matrix[0].size();f++){
                if(matrix[e][f]==0) x.push_back(make_pair(e,f));
            }
        }
        for(int e=0;e<x.size();e++){
            setKaro(matrix,(x[e].first),(x[e].second));
        }
    }
};