class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101);
        int n=nums.size();
        int result=0;
        for(int e=0;e<n;e++){
            freq[nums[e]]++;
        }
        sort(begin(freq),end(freq));
        n=100;
        nums[0]=freq[n];
        while(n>0 && freq[n]==nums[0]){
            result+=freq[n];
            n--;
        }
        return result;
    }
};