class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26,0);
        int n=s.size();
        for(int e=0;e<n;e++){
            freq[s[e]-'a']++;
        }
        int result=0;
        for(int e=0;e<n;e++){
            if(freq[t[e]-'a']!=0){
                freq[t[e]-'a']--;
            }else result++;
        }
        return result;
    }
};