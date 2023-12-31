class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.size();
        int result=-1;
        int sub_result=0;
        for(int e=0;e<n;e++){
            char c=s[e];
            int f=n-1;
            for(;f>e;f--){
                if(s[f]==c) break;
            }
            if(f==e) continue;
            sub_result=(f-e)-1;
            result=max(result,sub_result);
        }
        return result;
    }
};