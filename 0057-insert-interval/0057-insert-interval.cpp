class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>> result;
        int e=0;
        for(;e<n;e++){
            if(intervals[e][1]<newInterval[0]){
                result.push_back(intervals[e]);
            }else if(newInterval[1]<intervals[e][0]) break;
            else{
                newInterval[0]=min(newInterval[0],intervals[e][0]);
                newInterval[1]=max(newInterval[1],intervals[e][1]);
            }
        }
        result.push_back(newInterval);
        while(e<n){
            result.push_back(intervals[e]);
            e++;
        }
        return result;
    }
};