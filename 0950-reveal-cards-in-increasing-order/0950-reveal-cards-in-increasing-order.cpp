class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        // First approach

        /*
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
        */

        // Second approach

        sort(begin(deck),end(deck));
        int n=deck.size();
        queue<int> q;
        vector<int> result(n);
        for(int e=0;e<n;e++) q.push(e);
        for(int e=0;e<n;e++){
            int index=q.front();
            q.pop();
            result[index]=deck[e];
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return result;
    }
};