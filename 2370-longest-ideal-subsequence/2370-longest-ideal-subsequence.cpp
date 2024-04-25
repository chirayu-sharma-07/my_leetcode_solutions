class Solution {
public:
    int longestIdealString(string s, int k) {
        int n=s.size();
        vector<int> vec(26);
        int result=0;
        for(int e=0;e<n;e++){
            int curr=s[e]-'a';
            int left=max(0, curr-k);
            int right=min(25,curr+k);
            int longest=0;
            for(int f=left;f<=right;f++){
                longest=max(longest,vec[f]);
            }
            vec[curr]=max(vec[curr],longest+1);
            result=max(result,vec[curr]);
        }
        return result;
    }
};