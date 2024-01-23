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

    /*
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
    */

    // Third Approach
    // By populating true to deserving indexes

    /*
    bool canJump(vector<int> &nums){
        int n=nums.size();
        if(n==1) return true;
        if(nums[0]==0) return false;
        vector<bool> populate(n,false);
        populate[0]=true;
        for(int e=0;e<n;e++){
            if(nums[e]>0 && populate[e]==true){
                int x=e+nums[e];
                int f=e+1;
                while(f<n && f<=x && populate[f]==true) f++;
                if(f==x+1) continue;
                while(f<n && f<=x){
                    populate[f]=true;
                    f++;
                }
                if(populate[n-1]==true) return true;
            }else{
                if(nums[e]==0){
                    if(e==n-1){
                        if(populate[e]==true) return true;
                        return false;
                    }else{
                        if(populate[e+1]==false) return false;
                    }
                }
            }
        }
        return populate[n-1];
    }
    */

    /*
    bool canJump(vector<int> &nums){
        int n=nums.size();
        if(n==1) return true;
        vector<bool> visited(n,false);
        for(int e=0;e<n;e++){
            if(e<n-1 && nums[e]==0 && visited[e+1]==false) return false;
            int num=nums[e];
            int f=e+1;
            while(f<n && num--){
                visited[f]=true;
                f++;
            }
        }
        return visited[n-1];
    }
    */

    bool canJump(vector<int> &nums){
        int n=nums.size();
        if(n==1) return true;
        vector<bool> visited(n,false);
        for(int e=0;e<n-1;e++){
            if(e+nums[e]>=n-1){
                return true;
            }
            if(nums[e]==0){
                int f=e+1;
                while(f<n){
                    if(visited[f]==true) break;
                    f++;
                }
                if(f==n) return false;
            }
            visited[e+nums[e]]=true;
        }
        for(int e=0;e<n;e++) cout<<visited[e]<<endl;
        return visited[n-1];
    }
};