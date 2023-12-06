class Solution {
public:
    int totalMoney(int n) {
        int result=0;
        int count=0;
        while(n/7>0){
            result+=28;
            result+=(count*7);
            n-=7;
            count++;
        }
        count*=n;
        result+=((n+1)*(n))/2;
        result+=count;
        return result;
    }
};