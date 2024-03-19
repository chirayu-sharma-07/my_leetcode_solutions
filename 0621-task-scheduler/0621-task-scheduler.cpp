class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int result=0;
        vector<int> freq(26,0);
        for(char &c:tasks){
            freq[c-'A']++;
        }
        priority_queue<int> pq;
        for(int &e:freq){
            if(e!=0){
                pq.push(e);
            }
        }
        while(!pq.empty()){
            vector<int> temp;
            for(int e=0;e<=n;e++){
                if(!pq.empty()){
                    int element=pq.top();
                    pq.pop();
                    element--;
                    temp.push_back(element);
                }
            }
            for(int &e:temp){
                if(e!=0){
                    pq.push(e);
                }
            }
            if(!pq.empty()){
                result+=n+1;
            }else result+=temp.size();
        }
        return result;
    }
};