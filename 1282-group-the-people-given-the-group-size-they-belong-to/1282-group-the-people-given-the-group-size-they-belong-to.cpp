class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int arr[groupSizes.size()];
        for(int e=0;e<groupSizes.size();e++) arr[e]=1;
        vector<vector<int>> result;
        for(int e=0;e<groupSizes.size();e++){
            if(arr[e]==0) continue;
            int value=groupSizes[e];
            vector<int> subResult;
            subResult.push_back(e);
            arr[e]=0;
            int g=value-1;
            for(int f=1;g!=0 && f<groupSizes.size();f++){
                if(groupSizes[f]==value && arr[f]==1){
                    subResult.push_back(f);
                    arr[f]=0;
                    g--;
                }
            }
            result.push_back(subResult);
        }
        return result;
    }
};