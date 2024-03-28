class Solution {
public:
    string str="";
    bool isPalindromicQuestionMark(int e,int f){
        while(e<f){
            if(str[e]!=str[f]) return false;
            e++;
            f--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        str=s;
        int n=s.size();
        int i=0;
        int j=0;
        for(int e=0;e<n;e++){
            for(int f=e;f<n;f++){
                if(isPalindromicQuestionMark(e,f)){
                    if(f-e>j-i){
                        j=f;
                        i=e;
                    }
                }
            }
        }
        return s.substr(i,j-i+1);
    }
};