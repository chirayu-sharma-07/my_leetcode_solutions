class Solution {
public:
    int M=1000000007;
    int kInversePairs(int n, int k) {
        vector<vector<int>> bot_up(n+1, vector<int>(k+1));
        for(int e=0;e<=n;e++){
            bot_up[e][0]=1;
        }
        for(int e=1;e<=n;e++){
            long long sum=1;
            for(int f=1;f<=k;f++){
                sum+=bot_up[e-1][f];
                if(f>=e){
                    sum-=bot_up[e-1][f-e];
                }
                bot_up[e][f]=sum%M;
            }
        }
        return bot_up[n][k];
    }
};