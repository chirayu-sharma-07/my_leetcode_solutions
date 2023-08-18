class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,unordered_set<int>> adj;
        for(int e=0;e<roads.size();e++){
            int i=roads[e][0];
            int j=roads[e][1];
            adj[i].insert(j);
            adj[j].insert(i);
        }
        int result=0;
        for(int e=0;e<n-1;e++){
            for(int f=e+1;f<n;f++){
                int e_rank=adj[e].size();
                int f_rank=adj[f].size();
                int rank=e_rank+f_rank;
                if(adj[e].find(f)!=adj[e].end()) rank--;
                result=max(result,rank);
            }
        }
        return result;
    }
};