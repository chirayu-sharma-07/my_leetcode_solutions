class Solution {
public:
    int memo[101];
    int myFunction(int e,int n,string &s){
        if(memo[e]!=-1) return memo[e];
        if(e==n) return memo[e]=1;
        if(s[e]=='0') return memo[e]=0;
        int result=0;
        result+=myFunction(e+1,n,s);
        if(e+1<n){
            if(s[e]=='1' || (s[e]=='2' && s[e+1]<='6')) result+=myFunction(e+2,n,s);
        }
        return memo[e]=result;
    }
    int numDecodings(string s) {
        int n=s.size();
        memset(memo,-1,sizeof(memo));
        return myFunction(0,n,s);
    }
};