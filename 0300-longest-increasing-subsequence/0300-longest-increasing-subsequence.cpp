int memo[2501][2501];
class Solution {
public:
    
    // Approach One
    // Recursion + Memoization
    
    int n=0;
    int longestIncreasingSubsequence(int curr_index,int prev_index,vector<int>& nums){
        if(curr_index>=n) return 0;
        if(prev_index!=-1 && memo[curr_index][prev_index]!=-1) return memo[curr_index][prev_index];
        int take=0;
        if(prev_index==-1 || nums[prev_index]<nums[curr_index]){
            take=1+longestIncreasingSubsequence(curr_index+1,curr_index,nums);
        }
        int skip=longestIncreasingSubsequence(curr_index+1,prev_index,nums);
        if(prev_index==-1) return max(take,skip);
        return memo[curr_index][prev_index]=max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        if(n==1) return 1;
        memset(memo,-1,sizeof(memo));
        return longestIncreasingSubsequence(0,-1,nums);
    }
};