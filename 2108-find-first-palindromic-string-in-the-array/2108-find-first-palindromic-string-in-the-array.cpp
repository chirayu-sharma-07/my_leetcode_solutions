class Solution {
public:
    bool isPalindrome(string &s){
        int e=0;
        int f=s.size()-1;
        while(e<f){
            if(s[e]!=s[f]) return false;
            e++;f--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int n=words.size();
        for(int e=0;e<n;e++){
            if(isPalindrome(words[e])) return words[e];
        }
        return "";
    }
};