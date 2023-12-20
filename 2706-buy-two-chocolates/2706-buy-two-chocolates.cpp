class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(begin(prices),end(prices));
        int e=prices[0];
        int f=prices[1];
        if(e+f>money) return money;
        return money-(e+f);
    }
};