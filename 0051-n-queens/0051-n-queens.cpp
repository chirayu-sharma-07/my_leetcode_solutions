class Solution {
private:
    bool isValid(int row,int col,vector<string> &board,int n){
        int localRow=row;
        int localColumn=col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;col--;
        }
        row=localRow;
        col=localColumn;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        row=localRow;
        col=localColumn;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void solveNQueensProblem(int col,vector<string> &board,vector<vector<string>> &answer,int n){
        if(col==n){
            answer.push_back(board);
            return;
        }
        for(int e=0;e<n;e++){
            if(isValid(e,col,board,n)){
                board[e][col]='Q';
                solveNQueensProblem(col+1,board,answer,n);
                board[e][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answer;
        vector<string> board(n);
        string str;
        for(int e=0;e<n;e++){
            str+='.';
        }
        for(int e=0;e<n;e++){
            board[e]=str;
        }
        solveNQueensProblem(0,board,answer,n);
        return answer;
    }
};