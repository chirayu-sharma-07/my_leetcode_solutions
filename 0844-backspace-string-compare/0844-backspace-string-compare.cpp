class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1="";
        string s2="";
        for(int e=0;e<s.size();e++){
            if(s.at(e)!='#') s1.push_back(s.at(e));
            else if(s1.size()!=0){
                s1.pop_back();
            }
        }
        for(int e=0;e<t.size();e++){
            if(t.at(e)!='#') s2.push_back(t.at(e));
            else if(s2.size()!=0){
                s2.pop_back();
            }
        }
        if(s1.size()!=s2.size()) return false;
        for(int e=0;e<s1.size();e++){
            if(s1.at(e)!=s2.at(e)) return false;
        }
        return true;
    }
};