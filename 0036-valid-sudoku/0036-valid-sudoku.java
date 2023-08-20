class Solution {
    public boolean isValid(int e,int f,char[][] board){
        char digit=board[e][f];
        for(int i=0;i<9;i++){
            if(board[i][f]==digit && i!=e) return false;
            if(board[e][i]==digit && i!=f) return false;
            if(board[3*(e/3)+i/3][3*(f/3)+i%3]==digit && e!=(3*(e/3)+i/3) && f!=(3*(f/3)+i%3)) return false;
        }
        return true;
    }
    public boolean isValidSudoku(char[][] board) {
        for(int e=0;e<9;e++){
            for(int f=0;f<9;f++){
                if(board[e][f]!='.'){
                    if(!(isValid(e,f,board))) return false; 
                }
            }
        }
        return true;
    }
}