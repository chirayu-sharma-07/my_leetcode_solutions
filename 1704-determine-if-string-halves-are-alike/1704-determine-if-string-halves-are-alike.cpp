class Solution {
public:
    bool halvesAreAlike(string s) {
        int count=0;
        int n=s.size();
        int e=0;
        while(e<n/2){
            if(s[e]=='a' || s[e]=='A' || s[e]=='e' || s[e]=='E' || s[e]=='i' || s[e]=='I' || s[e]=='o' || s[e]=='O' || s[e]=='u' || s[e]=='U') count++;
            e++;
        }
        while(e<n){
            if(s[e]=='a' || s[e]=='A' || s[e]=='e' || s[e]=='E' || s[e]=='i' || s[e]=='I' || s[e]=='o' || s[e]=='O' || s[e]=='u' || s[e]=='U') count--;
            e++;
        }
        if(count!=0) return false;
        return true;
    }
};