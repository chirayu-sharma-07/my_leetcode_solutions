class Solution {
public:
    int n=0;
    int memo[2501][2501];
    int solveKarkeLao(int curr_index,int last_index,vector<int>& nums){
        if(curr_index>=n) return 0;
        if(last_index!=-1 && memo[curr_index][last_index]!=-1) return memo[curr_index][last_index];
        int take=0;
        if(last_index==-1 || nums[last_index]<nums[curr_index]){
            take=1+solveKarkeLao(curr_index+1,curr_index,nums);
        }
        int skip=solveKarkeLao(curr_index+1,last_index,nums);
        if(last_index==-1) return max(take,skip);
        return memo[curr_index][last_index]=max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        if(n==1) return n;
        memset(memo,-1,sizeof(memo));
        return solveKarkeLao(0,-1,nums);
    }
};