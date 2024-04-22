class Solution {
public:
    void myFunction(queue<string> &q,string &curr,unordered_set<string> &mySet){
        for(int e=0;e<4;e++){
            char c=curr[e];
            char d=c=='0'?'9':c-1;
            char i=c=='9'?'0':c+1;
            curr[e]=d;
            if(mySet.find(curr)==mySet.end()){
                mySet.insert(curr);
                q.push(curr);
            }
            curr[e]=i;
            if(mySet.find(curr)==mySet.end()){
                mySet.insert(curr);
                q.push(curr);
            }
            curr[e]=c;
        }
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> mySet(begin(deadends),end(deadends));
        string start="0000";
        if(mySet.find(start)!=mySet.end()) return -1;
        queue<string> q;
        q.push(start);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();
                if(curr==target){
                    return level;
                }
                myFunction(q,curr,mySet);
            }
            level++;
        }
        return -1;
    }
};