class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str=s;
        for(int e=0;e<s.size()-1;e++){
            char c=str[0];
            str.erase(0,1);
            str.push_back(c);
            if(str==s) return true;
        }
        return false;
    }
};