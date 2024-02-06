class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        int n=strs.size();
        unordered_set<string> mySet;
        unordered_map<string,int> myMap;
        int count=0;
        for(int e=0;e<n;e++){
            string s=strs[e];
            sort(begin(s),end(s));
            if(mySet.find(s)==mySet.end()){
                mySet.insert(s);
                myMap[s]=count;
                vector<string> temp;
                temp.push_back(strs[e]);
                result.push_back(temp);
                count++;
            }else{
                int index=myMap[s];
                result[index].push_back(strs[e]);
            }
        }
        return result;
    }
};