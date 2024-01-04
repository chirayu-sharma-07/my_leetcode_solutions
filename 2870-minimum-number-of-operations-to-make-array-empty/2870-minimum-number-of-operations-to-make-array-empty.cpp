class Solution {
public:
    int minOperations(vector<int>& nums) {

        // Approach one
        // Finding the frequency of each element and then playing
        // Brute force approach and code is not optimized

        /*
        int n=nums.size();
        if(n==1) return -1;
        int largest=-1;
        for(int e=0;e<n;e++){
            if(nums[e]>largest) largest=nums[e];
        }
        vector<int> freq(largest+1,0);
        for(int e=0;e<n;e++){
            freq[nums[e]]++;
        }
        for(int e=0;e<=largest;e++){
            if(freq[e]==1) return -1;
        }
        int result=0;
        for(int e=0;e<=largest;e++){
            if(freq[e]!=0){
                int x=freq[e];
                result+=x/3;
                x=x%3;
                if(x!=0) result++;
            }
        }
        return result;

        */

        // Appproach two
        // Sorting and then playing

        int n=nums.size();
        if(n==1) return -1;
        sort(begin(nums),end(nums));
        int result=0;
        for(int e=0;e<n;e++){
            int num=nums[e];
            int numCount=1;
            e++;
            while(e<n && nums[e]==num){
                numCount++;
                e++;
            }
            if(numCount==1) return -1;
            e--;
            result+=numCount/3;
            if(numCount%3!=0) result++;
        }
        return result;
    }
};