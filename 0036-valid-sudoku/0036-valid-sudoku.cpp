class Solution {
private:
    bool isValid(vector<vector<char>>& board,int e,int f){
        int digit=board[e][f];
        for(int i=0;i<9;i++){
            if(board[e][i]==digit){
                if(i!=f) return false;
            }
            if(board[i][f]==digit){
                if(i!=e) return false;
            }
            if(board[3*(e/3)+(i/3)][3*(f/3)+(i%3)]==digit){
                if((3*(e/3)+(i/3))!=e || (3*(f/3)+(i%3))!=f) return false;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int e=0;e<9;e++){
            for(int f=0;f<9;f++){
                if(board[e][f]!='.'){
                    if(!isValid(board,e,f)) return false;
                }
            }
        }
        return true;
    }
};