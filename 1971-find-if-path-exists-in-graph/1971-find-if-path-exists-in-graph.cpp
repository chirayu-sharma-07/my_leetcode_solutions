class Solution {
public:
    bool result=false;
    unordered_map<int,vector<int>> myMap;
    int d;
    void myFunction(vector<bool> &visited,int source){
        if(result) return;
        if(visited[source]) return;
        if(source==d) result=!result;
        visited[source]=!visited[source];
        int n=myMap[source].size();
        for(int e=0;e<n;e++){
            myFunction(visited,myMap[source][e]);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        d=destination;
        for(auto &e:edges){
            myMap[e[0]].push_back(e[1]);
            myMap[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n);
        myFunction(visited,source);
        return result;
    }
};