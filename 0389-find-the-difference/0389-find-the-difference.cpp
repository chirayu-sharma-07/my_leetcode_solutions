class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.size()==0) return t.at(0);
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int e=0;e<s.size();e++){
            if(s.at(e)!=t.at(e)) return t.at(e);
        }
        return t.at(t.size()-1);
    }
};