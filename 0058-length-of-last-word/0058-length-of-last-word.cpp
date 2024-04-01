class Solution {
public:
    int lengthOfLastWord(string s) {
        int e=s.size()-1;
        while(s[e]==' ') e--;
        int f=e;
        while(f>=0 && s[f]!=' ') f--;
        return e-f;
    }
};