class Solution {
public:
    int numberOfMatches(int n) {
        int result=0;
        while(n>1){
            result+=(n/2);
            if(n%2==0){
                n/=2;
            }else{
                n=(n/2)+1;
            }
        }
        return result;
    }
};