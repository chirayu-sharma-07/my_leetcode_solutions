class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        // First approach

        /*
        vector<pair<double,pair<int,int>>> vec;
        int n=arr.size();
        for(int e=0;e<n;e++){
            for(int f=e+1;f<n;f++){
                vec.push_back({(double)arr[e]/arr[f],{arr[e],arr[f]}});
            }
        }
        sort(begin(vec),end(vec));
        return {vec[k-1].second.first,vec[k-1].second.second};
        */

        // Second approach

        priority_queue<vector<double>> pq;
        int n=arr.size();
        for(int e=0;e<n;e++){
            for(int f=e+1;f<n;f++){
                pq.push({(double)arr[e]/arr[f],(double)e,(double)f});
                if(pq.size()>k) pq.pop();
            }
        }
        vector<double> vec=pq.top();
        return {arr[vec[1]],arr[vec[2]]};
    }
};