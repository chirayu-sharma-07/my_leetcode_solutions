class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Approach one

        /*
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
        */

        // Approach two

        /*
        unordered_map<int,int> myMap;
        vector<int> result;
        for(auto &e:nums){
            myMap[e]++;
        }
        vector<pair<int,int>> vec;
        for(auto &e:myMap){
            vec.push_back(make_pair(e.second,e.first));
        }
        sort(begin(vec),end(vec));
        int e=vec.size()-1;
        while(k--){
            result.push_back(vec[e--].second);
        }
        return result;
        */

        /*
        int n=nums.size();
        unordered_map<int,int> myMap;
        for(int e=0;e<n;e++) myMap[nums[e]]++;
        vector<int> result;
        for(auto &e:myMap){
            if(e.second>=k) result.push_back(e.first);
        }
        return result;
        */

        unordered_map<int,int> myMap;
        int n=nums.size();
        for(int e=0;e<n;e++) myMap[nums[e]]++;
        vector<pair<int,int>> vec;
        for(auto &e:myMap){
            vec.push_back(make_pair(e.second,e.first));
        }
        sort(vec.begin(),vec.end());
        n=vec.size()-1;
        vector<int> result;
        while(k--){
            result.push_back(vec[n].second);
            n--;
        }
        return result;
    }
};