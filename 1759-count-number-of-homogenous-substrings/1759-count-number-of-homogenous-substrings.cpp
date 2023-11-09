class Solution {
public:
    int countHomogenous(string s) {
        int MOD=1000000007;
        long long result=0;
        for(int e=0;e<s.size();){
            long long count=1;
            char c=s.at(e);
            e++;
            while(e<s.size() && s.at(e)==c){
                 e++;
                 count++;
            }
            result+=(count*(count+1))/2;
        }
        result%=MOD;
        return result;
    }
};