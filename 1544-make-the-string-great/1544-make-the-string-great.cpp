class Solution {
public:
    string makeGood(string s) {
        int n=s.size();
        stack<char> st;
        for(int e=0;e<n;e++){
            if(!st.empty() && (st.top()-'a'==s[e]-'A' || st.top()-'A'==s[e]-'a')){
                st.pop();
                continue;
            }
            st.push(s[e]);
        }
        s="";
        while(!st.empty()){
            s=st.top()+s;
            st.pop();
        }
        return s;
    }
};