class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(begin(tokens),end(tokens));
        int result=0;
        int score=0;
        for(int e=0,f=tokens.size()-1;e<=f;){
            if(tokens[e]<=power){
                power-=tokens[e];
                e++;
                score++;
                if(result<score) result=score;
            }else{
                if(score>0){
                    score--;
                    power+=tokens[f];
                    f--;
                }else return result;
            }
        }
        return result;
    }
};