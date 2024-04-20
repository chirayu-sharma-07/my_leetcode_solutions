class Solution {

    /*
private:
    int g=0;
    int h=0;
    int m=0;
    int n=0;
    vector<vector<bool>> visited(m,vector<int>(n));
public:
    void myFunction(int e,int f,vector<vector<int>> &land){
        visited[e][f]=!visited[e][f];
        if(e+1<m && land[e+1][f]==1 && !visited[e+1][f]){
            if(f+1<n && land[e][f+1]==1 && !visited[e][f+1]){
                if(!(e+1<m && f+1<n && land[e+1][f+1]==1 && !visited[e+1][f+1])) return;
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m=land.size();
        n=land[0].size();
        vector<vector<int>> result;
        for(int e=0;e<m;e++){
            for(int f=0;f<n;f++){
                if(land[e][f]==1 && !visited[e][f]){
                    myFunction(e,f,land);
                    result.push_back({e,f,g,h});
                }
            }
        }
        return result;
    }
    */

private:
    int m=0;
    int n=0;
    int g=0;
    int h=0;
public:
    void myFunction(vector<vector<int>> &land,int e,int f){
        land[e][f]--;
        g=(g>e)?g:e;
        h=(h>f)?h:f;
        if(e-1>=0 && land[e-1][f]==1) myFunction(land,e-1,f);
        if(e+1<m && land[e+1][f]==1) myFunction(land,e+1,f);
        if(f-1>=0 && land[e][f-1]==1) myFunction(land,e,f-1);
        if(f+1<n && land[e][f+1]==1) myFunction(land,e,f+1);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m=land.size();
        n=land[0].size();
        vector<vector<int>> result;
        for(int e=0;e<m;e++){
            for(int f=0;f<n;f++){
                if(land[e][f]==1){
                    myFunction(land,e,f);
                    result.push_back({e,f,g,h});
                    g=0;
                    h=0;
                }
            }
        }
        return result;
    }
};