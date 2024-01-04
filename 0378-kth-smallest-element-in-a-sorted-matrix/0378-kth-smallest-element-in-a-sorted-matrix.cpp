class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n=matrix.size();
        for(int e=0;e<n;e++){
            for(int f=0;f<n;f++){
                pq.push(matrix[e][f]);
            }
        }
        for(int e=0;e<k-1;e++){
            pq.pop();
        }
        return pq.top();
    }
};