class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<pair<int,int>> helper={{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
        int m=img.size();
        int n=img[0].size();
        vector<vector<int>> result;
        vector<int> sub_result;
        for(int e=0;e<m;e++){
            sub_result.clear();
            for(int f=0;f<n;f++){
                int divisor=0;
                int dividend=0;
                for(int g=0;g<9;g++){
                    int i=helper[g].first;
                    int j=helper[g].second;
                    if(e+i>=0 && e+i<m && f+j>=0 && f+j<n){
                        //if(e+i==e && f+j==f) continue;
                        divisor++;
                        dividend+=img[e+i][f+j];
                    }
                }
                sub_result.push_back(dividend/divisor);
            }
            result.push_back(sub_result);
        }
        return result;
    }
};