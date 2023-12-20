class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        //Brute force approach
        
        /*
        sort(begin(prices),end(prices));
        int e=prices[0];
        int f=prices[1];
        if(e+f>money) return money;
        return money-(e+f);
        */

        //Smart approach
        int smallest=INT_MAX;
        int secondSmallest=smallest;
        int n=prices.size();
        int identifier=-1;
        for(int e=0;e<n;e++){
            if(smallest==prices[e]) identifier=smallest;
            if(prices[e]<smallest) smallest=prices[e];
        }
        if(smallest==identifier){
            if(smallest+smallest>money) return money;
            return money-(smallest+smallest);
        }
        for(int e=0;e<n;e++){
            if(prices[e]<secondSmallest && prices[e]>smallest) secondSmallest=prices[e];
        }
        if(smallest+secondSmallest>money) return money;
        return money-(smallest+secondSmallest);
    }
};