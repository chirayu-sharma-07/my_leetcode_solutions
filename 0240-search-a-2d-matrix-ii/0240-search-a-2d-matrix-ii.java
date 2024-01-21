class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m=matrix.length;
        int n=matrix[0].length;
        int e=0;
        int f=n-1;
        while(f>=0 && e<m){
            if(matrix[e][f]==target) return true;
            if(matrix[e][f]>target) f--;
            else e++;
        }
        return false;
    }
}