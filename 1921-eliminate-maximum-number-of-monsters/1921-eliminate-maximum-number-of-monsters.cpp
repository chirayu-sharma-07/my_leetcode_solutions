class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int size=dist.size();
        vector<int> time(size);
        for(int e=0;e<size;e++){
            time[e]=ceil((float)dist[e]/speed[e]);
        }
        sort(time.begin(),time.end());
        int result=1;
        int time_passed=1;
        for(int e=1;e<size;e++){
            if(time[e]-time_passed<=0) return result;
            result++;
            time_passed++;
        }
        return result;
    }
};