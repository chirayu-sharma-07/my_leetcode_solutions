class Solution {
public:
    int pivotInteger(int n) {
        int e=1;
        int prefix=1;
        int postfix=n;
        while(e<n){
            if(prefix<postfix){
                e++;
                prefix+=e;
            }else{
                n--;
                postfix+=n;
            }
        }
        return (prefix==postfix)?e:-1;
    }
};