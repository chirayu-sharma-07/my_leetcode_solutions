class Solution {
public:
    string maximumOddBinaryNumber(string s) {

        // First approach

        /*
        int zero_count=0;
        int one_count=0;
        int n=s.size();
        for(int e=0;e<n;e++){
            if(s[e]=='0') zero_count++;
            else one_count++;
        }
        s="";
        one_count--;
        while(one_count--){
            s+='1';
        }
        while(zero_count--){
            s+='0';
        }
        s+='1';
        return s;
        */

        // Second approach (Halwa code)

        sort(begin(s),end(s),greater<char>());
        s=s.substr(1,s.size());
        return s+='1';
    }
};