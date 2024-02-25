class Solution {
public:
    bool isVowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')?true:false;
    }
    string reverseVowels(string s) {
        int e=0;
        int f=s.size()-1;
        while(e<f){
            if(!isVowel(s[e]) || !isVowel(s[f])){
                if(!isVowel(s[e])) e++;
                if(!isVowel(s[f])) f--;
            }else{
                char c=s[e];
                s[e]=s[f];
                s[f]=c;
                e++;
                f--;
            }
        }
        return s;
    }
};