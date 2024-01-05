// int memo[2501][2501];
class Solution {
public:

    // Approach one
    // Recursive + Memoization

    /*
    int n=0;
    int longestIncreasingSubsequence(int curr_index,int prev_index,vector<int>& nums){
        if(curr_index>=n) return 0;
        if(prev_index!=-1 && memo[curr_index][prev_index]!=-1) return memo[curr_index][prev_index];
        int take=0;
        if(prev_index==-1 || nums[prev_index]<nums[curr_index]){
            take=1+longestIncreasingSubsequence(curr_index+1,curr_index,nums);
        }
        int skip=longestIncreasingSubsequence(curr_index+1,prev_index,nums);
        if(prev_index==-1) return (take<skip)?skip:take;
        return memo[curr_index][prev_index]=(take<skip)?skip:take;
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        if(n==1) return 1;
        memset(memo,-1,sizeof(memo));
        return longestIncreasingSubsequence(0,-1,nums);
    }
    */
    
    // Approach two
    // Bottom-up dp
    
    /*
    int lengthOfLIS(vector<int>& nums){
        int n=nums.size();
        if(n==1) return 1;
        vector<int> bot_up(n,1);
        int largest=1;
        for(int e=1;e<n;e++){
            int g=bot_up[e];
            for(int f=0;f<e;f++){
                if(nums[f]<nums[e] && g+bot_up[f]>bot_up[e]){
                    bot_up[e]=g+bot_up[f];
                    if(largest<bot_up[e]) largest=bot_up[e];
                }
            }
        }
        return largest;
    }
    */

    // Approach three
    // Patience sorting

    int lengthOfLIS(vector<int>& nums){
        int n=nums.size();
        if(n==1) return 1;
        vector<int> sorted_array;
        sorted_array.push_back(nums[0]);
        for(int e=1;e<n;e++){
            int f=0;
            while(f<sorted_array.size() && nums[e]>sorted_array[f]){
                f++;
            }
            if(f==sorted_array.size()) sorted_array.push_back(nums[e]);
            else{
                sorted_array[f]=nums[e];
            }
        }
        return sorted_array.size();
    }
};