class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> myMap;
        int n=nums.size();
        vector<int> result;
        for(int e=0;e<n;e++){
            myMap[nums[e]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto &a:myMap){
            pq.push(make_pair(a.second,a.first));
        }
        while(k--){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};