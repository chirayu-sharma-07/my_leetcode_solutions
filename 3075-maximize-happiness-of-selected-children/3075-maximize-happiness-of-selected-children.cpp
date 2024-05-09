class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

        // First approach (Unoptimized)

        /*
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
        */

        // Abhi optimize karke deta hoon

        sort(begin(happiness),end(happiness),greater<int>());
        long long result=0;
        int count=0;
        for(int e=0;k--;count++,e++){
            if(happiness[e]-count>0) result+=happiness[e]-count;
            else break;
        }
        return result;
    }
};