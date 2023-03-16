class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num%2!=0) return false;
        int e=1;
        int sum=0;
        while(e<=num/2){
            if(num%e==0) sum+=e;
            e++;
        }
        return num==sum;
    }
};