class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> xAxis;
        int n=points.size();
        for(int e=0;e<n;e++){
            xAxis.push_back(points[e][0]);
        }
        sort(begin(xAxis),end(xAxis));
        int diff=0;
        for(int e=0;e<n-1;e++){
            if(xAxis[e]==xAxis[e+1]) continue;
            if(xAxis[e+1]-xAxis[e]>diff) diff=xAxis[e+1]-xAxis[e];
        }
        return diff;
    }
};