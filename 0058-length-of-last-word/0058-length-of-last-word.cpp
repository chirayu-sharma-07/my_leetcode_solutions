class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size()-1;
        while(s[n]==' ') n--;
        int count=0;
        while(n>=0 && s[n]!=' '){
            n--;
            count++;
        }
        return count;
    }
};