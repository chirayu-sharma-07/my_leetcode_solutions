class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        // First approach (Not working with every testcase)
        
        /*
        int n=points.size();
        int result=0;
        vector<bool> visited(n,false);
        int visited_count=0;
        for(int e=0;e<n;e++){
            if(!visited[e]){
                visited[e]=true;
                visited_count++;
                int left=points[e][0];
                int right=points[e][1];
                int f=e+1;
                while(f<n){
                    if((points[f][0]>=left && points[f][0]<=right) || (points[f][1]>=left && points[f][1]<=right) || (left>=points[f][0] && left<=points[f][1]) || (right>=points[f][0] && right<=points[f][1])){
                        visited[f]=true;
                        visited_count++;
                    }
                    f++;
                }
                result++;
                if(visited_count==n) return result;
            }
        }
        return result;
        */

        // Second approach

        /*
        sort(begin(points),end(points));
        int n=points.size();
        vector<bool> visited(n);
        int result=0;
        for(int e=0;e<n;e++){
            if(!visited[e]){
                visited[e]=true;
                int f=e+1;
                int left=points[e][0];
                int right=points[e][1];
                while(f<n){
                    if(!visited[f]){
                        if(points[f][0]>=left && points[f][0]<=right){
                            visited[f]=true;
                        }
                    }
                    f++;
                }
                result++;
            }
        }
        return result;
        */

        // Third approach

        sort(begin(points),end(points));
        int n=points.size();
        int left=points[0][0];
        int right=points[0][1];
        int result=0;
        for(int e=1;e<n;e++){
            if(points[e][0]>right){
                result++;
                left=points[e][0];
                right=points[e][1];
            }else{
                left=(left>points[e][0])?left:points[e][0];
                right=(right<points[e][1])?right:points[e][1];
            }
        }
        return result+1;
    }
};