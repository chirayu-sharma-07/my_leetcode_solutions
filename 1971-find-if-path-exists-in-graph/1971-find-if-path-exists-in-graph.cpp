class Solution {
public:

    // First approach (Not a clean code)

    /*
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
    */

    // Same approach as previous (DFS) but code is clean

    int d=0;
    unordered_map<int,vector<int>> myMap;
    bool myFunction(int source,vector<bool> &visited){
        if(source==d) return true;
        if(visited[source]) return false;
        visited[source]=!visited[source];
        for(auto &e:myMap[source]){
            if(myFunction(e,visited)) return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        d=destination;
        vector<bool> visited(n);
        for(auto &e:edges){
            myMap[e[0]].push_back(e[1]);
            myMap[e[1]].push_back(e[0]);
        }
        return myFunction(source,visited);
    }
};