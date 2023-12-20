class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(begin(asteroids),end(asteroids));
        long long mas=(long long)mass;
        int n=asteroids.size();
        for(int e=0;e<n;e++){
            if((long long)asteroids[e]>mas) return false;
            else{
                mas+=(long long)asteroids[e];
            }
        }
        return true;
    }
};