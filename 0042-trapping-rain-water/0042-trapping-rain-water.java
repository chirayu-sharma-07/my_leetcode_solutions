class Solution {
    public int trap(int[] height) {
        int[] e=new int[height.length];
        int[] f=new int[e.length];
        e[0]=height[0];
        for(int i=1;i<height.length;i++){
            e[i]=Math.max(e[i-1],height[i]);
        }
        f[height.length-1]=height[height.length-1];
        for(int i=height.length-2;i>=0;i--){
            f[i]=Math.max(f[i+1],height[i]);
        }
        int result=0;
        for(int i=0;i<height.length;i++){
            result+=Math.min(e[i],f[i])-height[i];
        }
        return result;
    }
}