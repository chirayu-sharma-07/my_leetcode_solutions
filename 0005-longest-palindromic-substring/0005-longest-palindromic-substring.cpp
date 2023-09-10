class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int dp[n][n];
        int i=0;
        int j=0;
        int maxLength=-1;
        for(int e=0;e<n;e++) dp[e][e]=1;
        for(int e=0,f=1;f<n;e++,f++){
            if(s[e]==s[f]){
                maxLength=2;
                i=e;
                j=f;
            }
        }
        for(int e=0,f=1;f<n;e++,f++){
            if(s[e]==s[f]) dp[e][f]=1;
            else dp[e][f]=0;
        }
        for(int diff=2;diff<n;diff++){
            for(int e=0,f=e+diff;f<n;f++,e++){
                if(s[e]==s[f] && dp[e+1][f-1]==1){
                    if((f-e)+1>maxLength){
                        maxLength=(f-e)+1;
                        i=e;
                        j=f;
                    }
                    dp[e][f]=1;
                }
                else dp[e][f]=0;
            }
        }
        return s.substr(i,(j-i)+1);
    }
};