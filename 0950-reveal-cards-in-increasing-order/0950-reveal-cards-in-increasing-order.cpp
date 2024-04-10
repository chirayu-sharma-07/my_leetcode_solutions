class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(begin(deck),end(deck));
        int n=deck.size();
        bool flag=false;
        int e=0;
        int f=0;
        vector<int> result(n,0);
        while(e<n){
            if(!result[f]){
                if(!flag){
                    result[f]=deck[e];
                    e++;
                }
                flag=!flag;
            }
            f=(f+1)%n;
        }
        return result;
    }
};