class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s;
        int n=paths.size();
        for(int e=0;e<n;e++){
            if(s.find(paths[e][1])==s.end()){
                s.insert(paths[e][1]);
            }
        }
        unordered_set<string> t;
        for(int e=0;e<n;e++){
            if(t.find(paths[e][0])==t.end()){
                t.insert(paths[e][0]);
            }
        }
        for(auto &e:s){
            if(t.find(e)==t.end()) return e;
        }
        return "";
    }
};