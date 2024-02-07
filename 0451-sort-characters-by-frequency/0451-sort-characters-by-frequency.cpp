class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> myMap;
        int n=s.size();
        for(int e=0;e<n;e++){
            myMap[s[e]]++;
        }
        vector<pair<int,char>> vec;
        for(auto &e:myMap){
            vec.push_back(make_pair(e.second,e.first));
        }
        sort(vec.begin(),vec.end());
        n=vec.size()-1;
        string result="";
        while(n>=0){
            int times=vec[n].first;
            char c=vec[n].second;
            while(times--) result+=c;
            n--;
        }
        return result;
    }
};