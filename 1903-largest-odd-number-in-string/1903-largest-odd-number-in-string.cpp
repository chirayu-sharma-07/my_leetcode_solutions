class Solution {
public:
    string largestOddNumber(string num) {
        if((int)(num[num.size()-1])%2!=0) return num;
        int n=num.size();
        int e=0;
        for(;e<n;e++){
            if((int)(num[e])%2!=0) break;
        }
        if(e==n) return "";
        e=n-2;
        while(e>=0 && (int)(num[e])%2==0) e--;
        return num.substr(0,e+1);
    }
};