class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result; // O(N) space
        int n=intervals.size();
        int e=0;
        while(e<n){
            if(intervals[e][1]<newInterval[0]) result.push_back(intervals[e]);
            else if(intervals[e][0]>newInterval[1]){
                break;
            }else{
                newInterval[0]=(intervals[e][0]<newInterval[0])?intervals[e][0]:newInterval[0];
                newInterval[1]=(intervals[e][1]>newInterval[1])?intervals[e][1]:newInterval[1];
            }
            e++;
        }
        result.push_back(newInterval);
        while(e<n){
            result.push_back(intervals[e]);
            e++;
        }
        return result;
    }
};