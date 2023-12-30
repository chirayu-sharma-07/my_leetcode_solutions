class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n=words.size();
        if(n==1) return true;
        vector<int> freq(26,0);
        for(int e=0;e<n;e++){
            string s=words[e];
            int m=s.size();
            for(int f=0;f<m;f++){
                freq[s[f]-'a']++;
            }
        }
        for(int e=0;e<26;e++){
            if(freq[e]%n!=0) return false;
        }
        return true;
    }
};