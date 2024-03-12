class Solution {
public:
    vector<vector<char>> myBoard;
    string myWord="";
    int m=0;
    int n=0;
    int word_size=0;
    vector<vector<int>> helper={{0,1},{1,0},{-1,0},{0,-1}};
    bool checkKaro(int e,int f,int index){
        if(index==word_size) return true;
        if(e<0 || f<0 || e>=m || f>=n || myBoard[e][f]=='$') return false;
        if(myBoard[e][f]!=myWord[index]) return false;
        char c=myBoard[e][f];
        myBoard[e][f]='$';
        for(auto &help:helper){
            int new_e=e+help[0];
            int new_f=f+help[1];
            if(checkKaro(new_e,new_f,index+1)) return true;
        }
        myBoard[e][f]=c;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        myBoard=board;
        myWord=word;
        m=board.size();
        n=board[0].size();
        word_size=word.size();
        char c=word[0];
        for(int e=0;e<m;e++){
            for(int f=0;f<n;f++){
                if(c==board[e][f]){
                    if(checkKaro(e,f,0)) return true;
                }
            }
        }
        return false;
    }
};