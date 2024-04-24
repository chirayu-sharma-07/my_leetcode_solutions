class Solution {
public:
    int tribonacci(int n) {
        vector<int> vec(38);
        vec[0]=0;
        vec[1]=1;
        vec[2]=1;
        for(int e=3;e<38;e++){
            vec[e]=vec[e-1]+vec[e-2]+vec[e-3];
            if(e>=n) return vec[n];
        }
        return vec[n];
    }
};