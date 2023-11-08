class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int xAxis=abs(sx-fx);
        int yAxis=abs(sy-fy);
        if(xAxis==0 && yAxis==0){
            if(t==1) return false;
            return true;
        }
        int minTimeRequired=max(xAxis,yAxis);
        if(minTimeRequired>t) return false;
        return true;
    }
};