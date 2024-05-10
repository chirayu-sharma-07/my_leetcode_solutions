class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double,pair<int,int>>> vec;
        int n=arr.size();
        for(int e=0;e<n;e++){
            for(int f=e+1;f<n;f++){
                vec.push_back({(double)arr[e]/arr[f],{arr[e],arr[f]}});
            }
        }
        sort(begin(vec),end(vec));
        return {vec[k-1].second.first,vec[k-1].second.second};
    }
};