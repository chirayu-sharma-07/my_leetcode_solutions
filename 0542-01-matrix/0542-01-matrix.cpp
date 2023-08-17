class Solution {
private:
    int rows,columns;
public:
    bool isValidate(int e,int f){
        if(e<0 || f<0 || e>=rows || f>=columns) return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        rows=mat.size();
        columns=mat[0].size();
        queue<pair<int,int>> queue;
        vector<vector<int>> answer(rows,vector<int>(columns,-1));
        for(int e=0;e<rows;e++){
            for(int f=0;f<columns;f++){
                if(mat[e][f]==0){
                    queue.push({e,f});
                    answer[e][f]=0;
                }
            }
        }
        while(!queue.empty()){
            int e=queue.front().first;
            int f=queue.front().second;
            if(isValidate(e+1,f) && answer[e+1][f]==-1){
                queue.push({e+1,f});
                answer[e+1][f]=answer[e][f]+1;
            }
            if(isValidate(e-1,f) && answer[e-1][f]==-1){
                queue.push({e-1,f});
                answer[e-1][f]=answer[e][f]+1;
            }
            if(isValidate(e,f+1) && answer[e][f+1]==-1){
                queue.push({e,f+1});
                answer[e][f+1]=answer[e][f]+1;
            }
            if(isValidate(e,f-1) && answer[e][f-1]==-1){
                queue.push({e,f-1});
                answer[e][f-1]=answer[e][f]+1;
            }
            queue.pop();
        }
        return answer;
    }
};