class Solution {
public:
    int minimumLength(string s) {

        // First approach, Memory Limit Exceeded :(

        /*
        if(s.size()==1) return 1;
        int e=0;
        int f=s.size()-1;
        while(e<f){
            if(s[e]!=s[f]) return s.size();
            char c1=s[e];
            while(e<f && c1==s[e]) e++;
            if(e==f && s[e]==c1 && s[f]==c1) return 0;
            while(f>e && c1==s[f]) f--;
            if(e==f && s[e]==c1 && s[f]==c1) return 0;
            s=s.substr(e);
            s=s.substr(0,f-e+1);
            e=0;
            f=s.size()-1;
        }
        return s.size();
        */
        
        // Second approach (Piece of cake)

        int e=0;
        int f=s.size()-1;
        while(e<f && s[e]==s[f]){
            char c=s[e];
            while(e<f && s[e]==c) e++;
            while(f>=e && s[f]==c) f--;
        }
        return f-e+1;
    }
};