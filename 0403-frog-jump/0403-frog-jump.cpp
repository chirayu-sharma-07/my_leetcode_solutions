class Solution {
private:
    bool myFunction(int index,int lastStep,vector<int> &stones,vector<vector<int>> &dp){
        if(index==stones.size()-1) return true;
        if(dp[index][lastStep]!=-1) return dp[index][lastStep];
        int minStep=max(1,lastStep-1);
        int maxStep=lastStep+1;
        int index1=lower_bound(stones.begin(),stones.end(),stones[index]+minStep)-stones.begin();
        int index2=upper_bound(stones.begin(),stones.end(),stones[index]+maxStep)-stones.begin();
        bool x=false;
        for(int e=index1;e<index2;e++){
            x= x || myFunction(e,stones[e]-stones[index],stones,dp);
        }
        return dp[index][lastStep]=x;
    }
public:
    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp(stones.size(),vector<int>(stones.size(),-1));
        return myFunction(0,0,stones,dp);
    }
};