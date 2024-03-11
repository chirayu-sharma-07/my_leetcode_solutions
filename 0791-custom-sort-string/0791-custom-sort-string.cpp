class Solution {
public:
    string customSortString(string order, string s) {

        // First approach

        /*
        vector<int> freq(26,0);
        int n=s.size();
        for(int e=0;e<n;e++){
            freq[s[e]-'a']++;
        }
        s="";
        n=order.size();
        for(int e=0;e<n;e++){
            if(freq[order[e]-'a']){
                while(freq[order[e]-'a']){
                    s+=order[e];
                    freq[order[e]-'a']--;
                }
            }
        }
        for(n=0;n<26;n++){
            if(freq[n]){
                while(freq[n]){
                    s+=n+'a';
                    freq[n]--;
                }
            }
        }
        return s;
        */

        // Second approach

        unordered_map<char,int> myMap;
        for(auto &e:s){
            myMap[e]++;
        }
        s="";
        for(auto &e:order){
            if(myMap[e]){
                while(myMap[e]!=0){
                    s+=e;
                    myMap[e]--;
                }
            }
        }
        for(auto &e:myMap){
            if(e.second!=0){
                while(e.second!=0){
                    s+=e.first;
                    e.second--;
                }
            }
        }
        return s;
    }
};