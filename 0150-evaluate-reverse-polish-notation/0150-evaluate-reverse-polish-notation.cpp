class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        if(n==1){
            return stoi(tokens[0]);
        }
        stack<string> st;
        st.push(tokens[0]);
        st.push(tokens[1]);
        for(int e=2;e<n;e++){
            if(tokens[e]=="+" || tokens[e]=="-" || tokens[e]=="*" || tokens[e]=="/"){
                int b=stoi(st.top());
                st.pop();
                int a=stoi(st.top());
                st.pop();
                if(tokens[e]=="+") a=a+b;
                else if(tokens[e]=="-") a=a-b;
                else if(tokens[e]=="*") a=a*b;
                else a=a/b;
                st.push(to_string(a));
            }else{
                st.push(tokens[e]);
            }
        }
        return stoi(st.top());
    }
};