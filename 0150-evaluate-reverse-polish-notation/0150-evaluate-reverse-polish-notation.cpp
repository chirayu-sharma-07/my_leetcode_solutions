class Solution {
public:
    /*
    int evalRPN(vector<string>& tokens) {

        // Approach one

        
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
        

        // Approach two


        int n=tokens.size();
        if(n==1) return stoi(tokens[0]);
        unordered_set<string> us={"+","-","*","/"};
        stack<int> st;
        st.push(stoi(tokens[0]));
        st.push(stoi(tokens[1]));
        for(int e=0;e<n;e++){
            if(us.find(tokens[e])==us.end()){
                st.push(stoi(tokens[e]));
            }else{
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                if(tokens[e]=="+") a=a+b;
                else if(tokens[e]=="-") a=a-b;
                else if(tokens[e]=="*") a=a*b;
                else a=a/b;
                st.push(a);
            }
        }
        return st.top();
    }
    */


    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n=tokens.size();
        if(n==1) return stoi(tokens[0]);
        for(int e=0;e<n;e++){
            if(tokens[e]=="+" || tokens[e]=="-" || tokens[e]=="*" || tokens[e]=="/"){
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                if(tokens[e]=="+") a=a+b;
                else if(tokens[e]=="-") a=a-b;
                else if(tokens[e]=="*") a=a*b;
                else a=a/b;
                st.push(a);
            }else{
                st.push(stoi(tokens[e]));
            }
        }
        return st.top();
    }
};