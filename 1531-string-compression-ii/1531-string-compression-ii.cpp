int memo[101][27][101][101];
class Solution {
public:
    int solve(string &s,int i,int prev_char, int freq, int k){
        if(k<0) return INT_MAX;
        if(i>=s.length()) return 0;
        if(memo[i][prev_char][freq][k]!=-1) return memo[i][prev_char][freq][k];
        int delete_i=solve(s,i+1,prev_char,freq,k-1);
        int keep_i=0;
        if(s[i]-'a'!=prev_char){
            keep_i=1+solve(s,i+1,s[i]-'a',1,k);
        }else{
            int one_more_addition=0;
            if(freq==1 || freq==9 || freq==99){
                one_more_addition=1;
            }
            keep_i=one_more_addition+solve(s,i+1,prev_char,freq+1,k);
        }
        return memo[i][prev_char][freq][k]=(delete_i<keep_i)?delete_i:keep_i;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(memo,-1,sizeof(memo));
        return solve(s,0,26,0,k);
    }
};