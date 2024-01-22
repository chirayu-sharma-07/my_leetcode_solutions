class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> occurances(n+1,0);
        for(int e=0;e<n;e++) occurances[nums[e]]++;
        int a=0;
        int b=0;
        for(int e=1;e<=n;e++){
            if(occurances[e]==2) a=e;
            if(occurances[e]==0) b=e;
        }
        return {a,b};
    }
};