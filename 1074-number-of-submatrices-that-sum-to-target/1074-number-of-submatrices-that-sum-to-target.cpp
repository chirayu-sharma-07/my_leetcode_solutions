class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int result=0;
        for(int e=0;e<m;e++){
            for(int f=1;f<n;f++){
                matrix[e][f]+=matrix[e][f-1];
            }
        }
        for(int e=0;e<n;e++){
            for(int f=e;f<n;f++){
                unordered_map<int,int> mp;
                mp[0]++;
                int sum=0;
                for(int g=0;g<m;g++){
                    sum+=matrix[g][f]-((e>0)?matrix[g][e-1]:0);
                    if(mp.find(sum-target)!=mp.end()){
                        result+=mp[sum-target];
                    }
                    mp[sum]++;
                }
            }
        }
        return result;
    }
};