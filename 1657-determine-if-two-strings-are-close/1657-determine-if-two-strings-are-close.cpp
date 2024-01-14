class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        int n=word1.size();
        vector<int> freq1(26);
        vector<int> freq2(26);
        for(int e=0;e<n;e++){
            freq1[word1[e]-'a']++;
            freq2[word2[e]-'a']++;
        }
        for(int e=0;e<26;e++){
            if((freq1[e]!=0 && freq2[e]==0) || (freq1[e]==0 && freq2[e]!=0)) return false;
        }
        sort(begin(freq1),end(freq1));
        sort(begin(freq2),end(freq2));
        return freq1==freq2;
    }
};