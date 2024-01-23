class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        // Approach one

        /*
        int n=nums.size();
        int m=n/3;
        vector<int> result;
        sort(begin(nums),end(nums));
        for(int e=0;e<n;e++){
            int num=nums[e];
            e++;
            int count=1;
            while(e<n && nums[e]==num){
                count++;
                e++;
            }
            if(count>m) result.push_back(num);
            e--;
        }
        return result;
        */

        // Approach two

        unordered_map<int,int> myMap;
        int n=nums.size();
        vector<int> result;
        for(int e=0;e<n;e++){
            myMap[nums[e]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto &e:myMap){
            pq.push(make_pair(e.second,e.first));
        }
        if(!pq.empty() && pq.top().first>n/3){
            result.push_back(pq.top().second);
            pq.pop();
            if(!pq.empty() && pq.top().first>n/3){
                result.push_back(pq.top().second);
                pq.pop();
                if(!pq.empty() && pq.top().first>n/3) result.push_back(pq.top().second);
            }
        }
        return result;      
    }
};