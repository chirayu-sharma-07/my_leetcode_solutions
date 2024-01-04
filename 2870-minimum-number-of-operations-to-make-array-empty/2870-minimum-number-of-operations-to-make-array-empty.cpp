class Solution {
public:
    int minOperations(vector<int>& nums) {
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
    }
};