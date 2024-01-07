class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        unordered_map<long,int> mp[n];
        for(int e=0;e<n;e++){
            for(int f=0;f<e;f++){
                long diff=(long)nums[e]-nums[f];
                auto it=mp[f].find(diff);
                int count_at_f=(it==end(mp[f]))?0:it->second;
                mp[e][diff]+=count_at_f+1;
                result+=count_at_f;
            }
        }
        return result;
    }
};