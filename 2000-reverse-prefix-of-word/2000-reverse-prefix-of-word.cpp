class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n=word.size();
        int e=0;
        while(e<n && word[e]!=ch) e++;
        if(e==n) return word;
        n=0;
        while(n<e){
            char c=word[n];
            word[n]=word[e];
            word[e]=c;
            n++;
            e--;
        }
        return word;
    }
};