class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int e=0;
        int f=1;
        int faayda=0;
        while(f<prices.size()){
            if(prices[e]<prices[f]){
                int profit=prices[f]-prices[e];
                faayda=max(faayda,profit);
                f++;
            }else{
                e=f;f++;
            }
        }
        return faayda;
    }
};