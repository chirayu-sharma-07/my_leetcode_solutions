class Solution {
public:
    int missingNumber(vector<int>& nums) {

        // Noob approach (First approach)
        
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
        
        /*
        int n=nums.size();
        int sum=n*(n+1)/2;
        for(int e=0;e<n;e++) sum-=nums[e];
        return sum;
        */
        
        // Fourth approach
        
        /*
        sort(begin(nums),end(nums));
        int n=nums.size();
        for(int e=0;e<n;e++){
            if(e!=nums[e]) return e;
        }
        return n;
        */
        
        // Fifth approach
        
        /*
        int n=nums.size();
        int result=n;
        for(int e=0;e<n;e++){
            result=result^e;
            result=result^nums[e];
        }
        return result;
        */
        
        // Sixth approach
        
        sort(begin(nums),end(nums));
        int e=0;
        int f=nums.size()-1;
        int result=f+1;
        while(e<=f){
            int mid=e+(f-e)/2;
            if(nums[mid]>mid){
                result=mid;
                f=mid-1;
            }else e=mid+1;
        }
        return result;
    }
};