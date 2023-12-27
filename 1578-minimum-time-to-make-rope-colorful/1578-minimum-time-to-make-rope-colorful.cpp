class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {

        // First approach 

        /*
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
        */

        // Second approach

        int n=neededTime.size();
        int result=0;
        for(int e=0;e<n-1;e++){
            if(colors[e]==colors[e+1]){
                int largest=0;
                int sum=0;
                while(e<n-1 && colors[e]==colors[e+1]){
                    if(largest<neededTime[e]) largest=neededTime[e];
                    sum+=neededTime[e];
                    e++;
                }
                if(largest<neededTime[e]) largest=neededTime[e];
                sum+=neededTime[e];
                result+=sum-largest;
            }
        }
        return result;
    }
};