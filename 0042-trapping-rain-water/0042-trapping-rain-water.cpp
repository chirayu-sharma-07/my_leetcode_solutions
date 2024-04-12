class Solution {
public:
    int n=0;
    vector<int> height;
    void find_left_max(vector<int> &left_max){
        left_max[0]=height[0];
        for(int e=1;e<n;e++){
            left_max[e]=max(height[e],left_max[e-1]);
        }
    }
    void find_right_max(vector<int> &right_max){
        right_max[n-1]=height[n-1];
        for(int e=n-2;e>=0;e--){
            right_max[e]=max(right_max[e+1],height[e]);
        }
    }
    int trap(vector<int>& h) {
        height=h;
        n=height.size();
        vector<int> left_max(n);
        vector<int> right_max(n);
        find_left_max(left_max);
        find_right_max(right_max);
        int result=0;
        for(int e=0;e<n;e++){
            result+=min(left_max[e],right_max[e])-height[e];
        }
        return result;
    }
};