class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // Approach One
        // Slow code in terms of runtime but optimized in memory terms

        /*
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
        */

        // Approach Two
        // Fast in terms of runtime

        vector<vector<int>> result;
        vector<int> sub_result;
        int n=nums.size();
        int largest=-1;
        for(int e=0;e<n;e++){
            if(nums[e]>largest) largest=nums[e];
        }
        vector<int> freq(largest+1,0);
        for(int e=0;e<n;e++){
            freq[nums[e]]++;
        }
        while(true){
            sub_result.clear();
            int e=0;
            for(;e<=largest;e++){
                if(freq[e]!=0){
                    sub_result.push_back(e);
                    freq[e]--;
                }
            }
            if(e==largest+1 && sub_result.size()==0) break;
            result.push_back(sub_result);
        }
        return result;
    }
};