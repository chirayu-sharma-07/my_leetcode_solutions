class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int result=0;
        int prev_one_count=0;
        for(int e=0;e<n;e++){
            string s=bank[e];
            int m=s.size();
            int one_count=0;
            for(int f=0;f<m;f++){
                if(s[f]=='1') one_count++;
            }
            result+=prev_one_count*one_count;
            if(one_count!=0){
                prev_one_count=one_count;
            }
        }
        return result;
    }
};