class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        if(points.size()==1) return 0;
        int points_size=points.size();
        int result=0;
        for(int e=1;e<points_size;e++){
            if(abs(points[e][0]-points[e-1][0])>abs(points[e][1]-points[e-1][1])) result+=abs(points[e][0]-points[e-1][0]);
            else result+=abs(points[e][1]-points[e-1][1]);
        }
        return result;
    }
};