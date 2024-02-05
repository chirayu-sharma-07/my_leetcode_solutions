class Solution {
public:
    int firstUniqChar(string s) {
        // First approach
        /*
        unordered_map<char,int> mp;
        int n=s.size();
        for(int e=0;e<n;e++){
            mp[s[e]]++;
        }
        for(int e=0;e<n;e++){
            if(mp[s[e]]==1) return e;
        }
        return -1;
        */

        // Second approach

        int n=s.size();
        int freq[26]={0};
        for(int e=0;e<n;e++) freq[s[e]-'a']++;
        for(int e=0;e<n;e++){
            if(freq[s[e]-'a']==1) return e;
        }
        return -1;
    }
};