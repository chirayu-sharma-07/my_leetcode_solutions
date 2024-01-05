class Solution {
public:

    // Brute force approach
    // Time Limit exceeded code

    /*
    int n=0;
    bool myFunction(int e,vector<int> &nums,vector<int> &memo){
        if(memo[e]!=-1) return true;
        if(e>=n) return false;
        if(e==n-1) return true;
        int num=nums[e];
        for(int f=0;f<num;f++){
            if(myFunction(e+(num-f),nums,memo)){
                memo[e]=e+(num-f);
                return true;
            }
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        n=nums.size();
        vector<int> memo(n+1,-1);
        return myFunction(0,nums,memo);
    }
    */

    // Second approach
    // Recursion + Memoization

    int n=0;
    bool myFunction(int e,vector<int> &nums,vector<int> &memo){
        if(e>=n) return true;
        if(e==n-1){
            memo[e]=1;
            return true;
        }
        if(memo[e]!=0){
            if(memo[e]==1) return true;
            return false;
        }
        for(int f=1;f<=nums[e];f++){
            if(myFunction(e+f,nums,memo)==true){
                memo[e]=1;
                return true;
            }
        }
        memo[e]=-1;
        return false;
    }
    bool canJump(vector<int> &nums){
        n=nums.size();
        if(n==1) return true;
        vector<int> memo(n,0);
        return myFunction(0,nums,memo);
    }
};