class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(begin(s),end(s));
        int n=g.size();
        int m=s.size();
        int e=0;
        for(int f=0;e<n && f<m;f++){
            if(g[e]<=s[f]) e++;
        }
        return e;
    }
};