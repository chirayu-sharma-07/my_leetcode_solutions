class Solution {
public:
    string str="";
    bool isPalindrome(int e,int f){
        while(e<=f){
            if(str[e]!=str[f]) return false;
            e++;
            f--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n=s.size();
        str=s;
        int result=n;
        for(int e=0;e<n-1;e++){
            for(int f=e+1;f<n;f++){
                if(isPalindrome(e,f)) result++;
            }
        }
        return result;
    }
};