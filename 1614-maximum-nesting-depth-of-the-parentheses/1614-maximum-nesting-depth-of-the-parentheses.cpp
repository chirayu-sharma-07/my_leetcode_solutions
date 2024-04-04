class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int result=0;
        int sub_result=0;
        for(int e=0;e<n;e++){
            if(s[e]=='(') sub_result++;
            result=max(result,sub_result);
            if(s[e]==')') sub_result--;
        }
        return result;
    }
};