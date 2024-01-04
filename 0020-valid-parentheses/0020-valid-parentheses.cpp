class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.size();
        if(n%2!=0) return false;
        if(s[0]==']' || s[0]==')' || s[0]=='}') return false;
        st.push(s[0]);
        for(int e=1;e<n;e++){
            if(s[e]=='(') st.push('(');
            else if(s[e]=='[') st.push('[');
            else if(s[e]=='{') st.push('{');
            else if(st.empty()) return false;
            else if(s[e]==')'){
                if(st.top()!='(') return false;
                st.pop();
            }else{
                if(s[e]==']'){
                    if(st.top()!='[') return false;
                    st.pop();
                }else{
                    if(st.top()!='{') return false;
                    st.pop();
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }
};