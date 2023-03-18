class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(target<matrix[0][0] || target>matrix[matrix.length-1][matrix[0].length-1]) return false;
        int e=0;
        int f=matrix.length-1;
        while(e<=f){
            int mid=e+((f-e)/2);
            if(target==matrix[mid][matrix[0].length-1]) return true;
            if(target<matrix[mid][matrix[0].length-1]) f=mid-1;
            else e=mid+1;
        }
        f=0;
        int g=matrix[0].length-1;
        while(f<=g){
            int mid=f+((g-f)/2);
            if(target==matrix[e][mid]) return true;
            if(target<matrix[e][mid]) g=mid-1;
            else f=mid+1;
        }
        return false;
    }
}