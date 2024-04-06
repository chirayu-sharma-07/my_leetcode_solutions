class Solution {
public:
    bool isVowel(char c){
        if(c=='A' || c=='a' || c=='E' || c=='e' || c=='I' || c=='i' || c=='O' || c=='o' || c=='U' || c=='u') return true;
        return false;
    }
    string reverseVowels(string s) {
        vector<int> vowel_indexes;
        int n=s.size();
        for(int e=0;e<n;e++){
            if(isVowel(s[e])) vowel_indexes.push_back(e);
        }
        for(int e=0,f=vowel_indexes.size()-1;e<f;e++,f--){
            char g=s[vowel_indexes[e]];
            s[vowel_indexes[e]]=s[vowel_indexes[f]];
            s[vowel_indexes[f]]=g;
        }
        return s;
    }
};