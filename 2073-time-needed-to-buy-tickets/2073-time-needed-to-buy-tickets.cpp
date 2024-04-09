class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        int result=0;
        while(true){
            for(int e=0;e<n;e++){
                if(tickets[k]==0) return result;
                if(tickets[e]==0) continue;
                tickets[e]--;
                result++;
            }
        }
        return 0;
    }
};