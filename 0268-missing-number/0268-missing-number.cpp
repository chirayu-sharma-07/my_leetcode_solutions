class Solution {
public:
    int missingNumber(vector<int>& nums) {

        // Noob approach
        
        /*
        unordered_set<int> mySet;
        int n=nums.size();
        for(int e=0;e<n;e++){
            mySet.insert(nums[e]);
        }
        n++;
        while(n--){
            if(mySet.find(n)==mySet.end()) return n;
        }
        return 0;
        */
        
        // Second approach
        
        /*
        sort(begin(nums),end(nums));
        if(nums[0]!=0) return 0;
        int n=nums.size();
        for(int e=0;e<n-1;e++){
            if((nums[e]+1)!=nums[e+1]) return nums[e]+1;
        }
        return n;
        */
        
        // Third approach
        
        int n=nums.size();
        int sum=n*(n+1)/2;
        for(int e=0;e<n;e++) sum-=nums[e];
        return sum;
    }
};