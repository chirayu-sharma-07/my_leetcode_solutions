class Solution {
public:

    // Approach one
    // Recursion + Memoization
    
    /*
    int m=0;
    int n=0;
    int memo[1001][1001];
    int myFunction(string &s,string &t,int e,int f){
        if(e==m || f==n) return 0;
        if(memo[e][f]!=-1) return memo[e][f];
        if(s[e]==t[f]) return memo[e][f]=1+myFunction(s,t,e+1,f+1);
        int take_s=myFunction(s,t,e,f+1);
        int take_t=myFunction(s,t,e+1,f);
        return memo[e][f]=max(take_s,take_t);
    }
    int longestCommonSubsequence(string text1, string text2) {
        m=text1.size();
        n=text2.size();
        memset(memo,-1,sizeof(memo));
        return myFunction(text1,text2,0,0);
    }
    */


    // Approach two
    // Little bit optimized than previous approach

    string s,t;
    int m,n;
    int memo[1001][1001];
    int findLongestCommonSubsequence(int e,int f){
        if(e==m || f==n) return 0;
        if(memo[e][f]!=-1) return memo[e][f];
        if(s[e]==t[f]) return memo[e][f]=1+findLongestCommonSubsequence(e+1,f+1);
        return memo[e][f]=max(findLongestCommonSubsequence(e+1,f),findLongestCommonSubsequence(e,f+1));
    }
    int longestCommonSubsequence(string s1,string s2){
        s=s1;
        t=s2;
        m=s.size();
        n=t.size();
        memset(memo,-1,sizeof(memo));
        return findLongestCommonSubsequence(0,0);
    }
};