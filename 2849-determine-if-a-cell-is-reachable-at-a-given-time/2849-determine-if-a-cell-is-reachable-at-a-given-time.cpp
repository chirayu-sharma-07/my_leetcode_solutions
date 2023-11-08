class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx && sy==fy){
            if(t==1) return false;
            else return true;
        }
        int e=0;
        int f=e;
        if(sx>fx)
        {
            e=sx-fx;
        }
        else
        {
            e=fx-sx;
        }
        if(sy>fy)
        {
            f=sy-fy;
        }
        else
        {
            f=fy-sy;
        }
        int g=0;
        if(e>f) g=e;
        else g=f;
        if(g>t) return false;
        return true;
    }
};