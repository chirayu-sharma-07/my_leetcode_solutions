class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sub_result;
        int n=nums.size();
        vector<int> freq(n+1,0);
        for(int e=0;e<n;e++){
            freq[nums[e]]++;
        }
        while(true){
            sub_result.clear();
            int e=0;
            for(;e<=n;e++){
                if(freq[e]!=0){
                    sub_result.push_back(e);
                    freq[e]--;
                }
            }
            if(e==n+1 && sub_result.size()==0) break;
            result.push_back(sub_result);
        }
        return result;
    }
};