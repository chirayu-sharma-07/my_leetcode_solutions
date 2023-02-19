class Solution {
    public int maxArea(int[] height) {
        int result=0;
        for(int e=0,f=height.length-1;e<f;){
            int g=Math.min(height[e],height[f]);
            int h=g*(f-e);
            if(h>result) result=h;
            if(g==height[e]) e++;
            else f--;
        }
        return result;
    }
}