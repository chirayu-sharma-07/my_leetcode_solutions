class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> arr(26,0);
        int n=s.size();
        for(int e=0;e<n;e++){
            arr[(int)s[e]-97]++;
        }
        for(int e=0;e<n;e++){
            arr[(int)t[e]-97]--;
        }
        for(int e=0;e<26;e++){
            if(arr[e]!=0) return false;
        }
        return true;
    }
};