class Solution {
    public void setZeroes(int[][] matrix) {
    int num_rows = matrix.length;
    int num_cols = matrix[0].length;
    Stack<Integer> stack1=new Stack<>();
    Stack<Integer> stack2=new Stack<>();
    for(int e=0;e<num_rows;e++){
        for(int f=0;f<num_cols;f++){
            if(matrix[e][f]==0){
                stack1.push(e);
                stack2.push(f);
            }
        }
    }
    if(stack1.size()==(num_cols*num_rows)) return;
    while(!(stack1.empty())){
        int e=stack1.pop();
        int f=stack2.pop();
        for(int i=e;i-1>-1;i--){
            matrix[i-1][f]=0;
        }
        for(int i=f;i+1<num_cols;i++){
            matrix[e][i+1]=0;
        }
        for(int i=e;i+1<num_rows;i++){
            matrix[i+1][f]=0;
        }
        for(int i=f;i-1>-1;i--){
            matrix[e][i-1]=0;
        }
    }    
    }
}