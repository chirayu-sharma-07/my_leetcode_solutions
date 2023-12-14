class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> e_one(m,0);
        vector<int> e_zero(m,0);
        vector<int> f_one(n,0);
        vector<int> f_zero(n,0);
        for(int e=0;e<m;e++){
            for(int f=0;f<n;f++){
                if(grid[e][f]==1){
                    e_one[e]++;
                    f_one[f]++;
                }
                else{
                    e_zero[e]++;
                    f_zero[f]++;
                }
            }
        }
        for(int e=0;e<m;e++){
            for(int f=0;f<n;f++){
                grid[e][f]=(e_one[e]+f_one[f]-e_zero[e]-f_zero[f]);
            }
        }
        return grid;
    }
};