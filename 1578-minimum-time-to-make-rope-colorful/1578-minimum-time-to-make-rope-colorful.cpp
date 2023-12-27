class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=neededTime.size();
        int result=0;
        for(int e=0;e<n-1;e++){
            if(colors[e]==colors[e+1]){
                priority_queue<int> pq;
                int count=neededTime[e];
                pq.push(count);
                e++;
                while(e<n-1 && colors[e]==colors[e+1]){
                    count+=neededTime[e];
                    pq.push(neededTime[e]);
                    e++;
                }
                count+=neededTime[e];
                pq.push(neededTime[e]);
                result+=count-pq.top();
            }
        }
        return result;
    }
};