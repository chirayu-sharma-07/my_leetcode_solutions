class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> L2R(n,1);
        vector<int> R2L(n,1);
        for(int e=1;e<n;e++){
            if(ratings[e]>ratings[e-1]){
                L2R[e]=L2R[e-1]+1;
            }
        }
        for(int e=n-2;e>=0;e--){
            if(ratings[e]>ratings[e+1]){
                R2L[e]=R2L[e+1]+1;
            }
        }
        int result=0;
        for(int e=0;e<n;e++){
            result+=(L2R[e]>R2L[e])?L2R[e]:R2L[e];
        }
        return result;
    }
};