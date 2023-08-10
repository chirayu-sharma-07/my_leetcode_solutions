class Solution {
    public int[][] transpose(int[][] matrix) {
        int result[][]=new int[matrix[0].length][matrix.length];
        for(int e=0;e<matrix.length;e++){
            for(int f=0;f<matrix[0].length;f++){
                result[f][e]=matrix[e][f];
            }
        }
        return result;
    }
}