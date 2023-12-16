class Solution {
public:
    bool isAnagram(string s, string t) {
        //First approach by sam_chirayu
        // TC - 98.77% acceptance
        // SC - 79.21% acceptance
        // Both are more than my 12th percentage ;)
        /*
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
        */
        //Second approach by sam_chirayu
        //This is brute force approach (sorting involved)
        if(s.size()!=t.size()) return false;
        sort(begin(s),end(s));
        sort(t.begin(),t.end());
        int n=s.size();
        for(int e=0;e<n;e++){
            if(s[e]!=t[e]) return false;
        }
        return true;
    }
};