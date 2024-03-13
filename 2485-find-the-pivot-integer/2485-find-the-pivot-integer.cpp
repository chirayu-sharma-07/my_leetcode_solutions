class Solution {
public:
    int pivotInteger(int n) {
        int e=1;
        int f=n;
        int prefix=1;
        int postfix=n;
        while(e<f){
            if(prefix<postfix){
                e++;
                prefix+=e;
            }else{
                f--;
                postfix+=f;
            }
        }
        return (prefix==postfix)?e:-1;
    }
};