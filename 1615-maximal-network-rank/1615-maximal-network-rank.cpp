class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> road(n,0);
        vector<vector<bool>> isVisited(n,vector<bool>(n,false));
        for(int e=0;e<roads.size();e++){
            int i=roads[e][0];
            int j=roads[e][1];
            road[i]++;
            road[j]++;
            isVisited[i][j]=true;
            isVisited[j][i]=true;
        }
        int answer=0;
        for(int e=0;e<n-1;e++){
            for(int f=e+1;f<n;f++){
                int i=road[e];
                int j=road[f];
                int total=i+j;
                if(isVisited[e][f] || isVisited[f][e]) total--;
                answer=max(total,answer);
            }
        }
        return answer;
    }
};