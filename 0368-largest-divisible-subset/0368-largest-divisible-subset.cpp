class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        vector<int> bot_up(n,1);
        vector<int> indexes(n,-1);
        int last_index=0;
        int length=1;
        for(int e=1;e<n;e++){
            for(int f=0;f<e;f++){
                if(nums[e]%nums[f]==0){
                    if(bot_up[e]<bot_up[f]+1){
                        bot_up[e]=bot_up[f]+1;
                        indexes[e]=f;
                    }  
                    if(bot_up[e]>length){
                        length=bot_up[e];
                        last_index=e;
                    }
                }
            }
        }
        vector<int> result;
        while(last_index!=-1){
            result.push_back(nums[last_index]);
            last_index=indexes[last_index];
        }
        return result;
    }
};