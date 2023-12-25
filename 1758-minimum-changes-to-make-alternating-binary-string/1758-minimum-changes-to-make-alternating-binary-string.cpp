class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int start_with_zero=0;
        int start_with_one=0;
        for(int e=0;e<n;e++){
            if(e%2==0){
                if(s[e]=='0') start_with_zero++;
                else start_with_one++;
            }else{
                if(s[e]=='0') start_with_one++;
                else start_with_zero++;
            }
        }
        return (start_with_zero<start_with_one)?start_with_zero:start_with_one;
    }
};