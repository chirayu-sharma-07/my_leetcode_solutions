class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        int n=s.size();
        for(int e=0;e<n;e++){
            mp[s[e]]++;
        }
        for(int e=0;e<n;e++){
            if(mp[s[e]]==1) return e;
        }
        return -1;
    }
};