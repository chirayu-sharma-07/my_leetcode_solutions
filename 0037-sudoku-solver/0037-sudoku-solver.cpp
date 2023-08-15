class Solution {
public:
    bool isValid(int row,int column,char digit,vector<vector<char>> &board){
        for(int e=0;e<9;e++){
            if(board[e][column]==digit) return false;
            if(board[row][e]==digit) return false;
            if(board[3*(row/3)+e/3][3*(column/3)+e%3]==digit) return false;
        }
        return true;
    }
    bool sudokuSolver(vector<vector<char>> &board){
        for(int e=0;e<board.size();e++){
            for(int f=0;f<board[0].size();f++){
                if(board[e][f]=='.'){
                    for(char digit='1';digit<='9';digit++){
                        if(isValid(e,f,digit,board)){
                            board[e][f]=digit;
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
    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board);
    }
};