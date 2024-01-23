class Solution {
public:
    int maxArea(vector<int>& height) {
        int result=INT_MIN;
        int e=0;
        int f=height.size()-1;
        while(e<f){
            result=max(result,(f-e)*((height[e]<height[f])?height[e]:height[f]));
            (height[e]<height[f])?e++:f--;
        }
        return result;
    }
};