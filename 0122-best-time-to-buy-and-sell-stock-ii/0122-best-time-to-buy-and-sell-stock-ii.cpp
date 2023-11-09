class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int final_profit=0;
        int itsTimeToBuyStock=prices[0];
        int sizeOfArray=prices.size();
        for(int e=1;e<sizeOfArray;e++){
            if(prices[e]<itsTimeToBuyStock) itsTimeToBuyStock=prices[e];
            else{
                int f=e+1;
                while(f<sizeOfArray && prices[f]>=prices[f-1]) f++;
                f--;
                final_profit+=prices[f]-itsTimeToBuyStock;
                e=f+1;
                if(e<sizeOfArray) itsTimeToBuyStock=prices[e];
            }
        }
        return final_profit;
    }
};