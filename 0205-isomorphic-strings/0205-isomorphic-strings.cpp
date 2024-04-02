class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> myMap;
        unordered_set<char> mySet;
        int n=s.size();
        for(int e=0;e<n;e++){
            char first_char=s[e];
            char second_char=t[e];
            if(myMap.find(first_char)!=myMap.end()){
                if(second_char!=myMap[first_char]) return false;
            }else{
                if(mySet.find(second_char)!=mySet.end()) return false;
                myMap[first_char]=second_char;
                mySet.insert(second_char);
            }
        }
        return true;
    }
};