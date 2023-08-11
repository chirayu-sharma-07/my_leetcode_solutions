class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        dp[0]=1;
        for(int e=0;e<coins.size();e++){
            for(int f=coins[e];f<=amount;f++){
                dp[f]+=dp[f-coins[e]];
            }
        }
        return dp[amount];
    }
};