class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string> result(n);
        vector<pair<int,int>> vec;
        for(int e=0;e<n;e++){
            vec.push_back({score[e],e});
        }
        sort(begin(vec),end(vec),[](const pair<int,int> &a,const pair<int,int> &b){
            return a.first>b.first;
        });
        for(int e=0;e<n;e++){
            int index=vec[e].second;
            if(e==0) result[index]="Gold Medal";
            else if(e==1) result[index]="Silver Medal";
            else if(e==2) result[index]="Bronze Medal";
            else result[index]=to_string(e+1);
        }
        return result;
    }
};