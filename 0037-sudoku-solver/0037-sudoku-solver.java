class Solution {
    public boolean isValid(int e,int f,char c,char[][] board){
        for(int i=0;i<9;i++){
            if(board[i][f]==c) return false;
            if(board[e][i]==c) return false;
            if(board[3*(e/3)+i/3][3*(f/3)+i%3]==c) return false;
        }
        return true;
    }
    public boolean sudokuSolver(char[][] board){
        for(int e=0;e<9;e++){
            for(int f=0;f<9;f++){
                if(board[e][f]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(e,f,c,board)){
                            board[e][f]=c;
                            if(sudokuSolver(board)) return true;
                            board[e][f]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    public void solveSudoku(char[][] board) {
        sudokuSolver(board);
    }
}