class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        unordered_set<int> mySet;
        unordered_map<int,int> myMap;
        for(int e=0;e<n;e++){
            if(mySet.find(matches[e][1])==mySet.end()) mySet.insert(matches[e][1]);
            myMap[matches[e][1]]++;
        }
        vector<vector<int>> result;
        vector<int> sub_result;
        for(int e=0;e<n;e++){
            if(mySet.find(matches[e][0])==mySet.end())
            {
                mySet.insert(matches[e][0]);
                sub_result.push_back(matches[e][0]);
            }
        }
        sort(begin(sub_result),end(sub_result));
        result.push_back(sub_result);
        sub_result.clear();
        for(const auto& pair:myMap){
            if(pair.second==1) sub_result.push_back(pair.first);
        }
        sort(begin(sub_result),end(sub_result));
        result.push_back(sub_result);
        return result;
    }
};