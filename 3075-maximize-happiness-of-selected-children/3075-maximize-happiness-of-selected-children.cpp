class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long result=0;
        priority_queue<int> pq;
        for(int &e:happiness) pq.push(e);
        int count=0;
        while(k--){
            if(pq.top()-count>0) result+=pq.top()-count;
            else break;
            pq.pop();
            count++;
        }
        return result;
    }
};