class Solution {
public:
    vector<int> getNSL(vector<int> &arr,int n){
        vector<int> result(n);
        stack<int> st;
        for(int e=0;e<n;e++){
            if(st.empty()) result[e]=-1;
            else{
                while(!st.empty() && arr[st.top()]>=arr[e]) st.pop();
                result[e]=st.empty()?-1:st.top();
            }
            st.push(e);
        }
        return result;
    }
    vector<int> getNSR(vector<int> &arr,int n){
        vector<int> result(n);
        stack<int> st;
        for(int e=n-1;e>=0;e--){
            if(st.empty()) result[e]=n;
            else{
                while(!st.empty() && arr[st.top()]>arr[e]) st.pop();
                result[e]=st.empty()?n:st.top();
            }
            st.push(e);
        }
        return result;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> NSL=getNSL(arr,n);
        vector<int> NSR=getNSR(arr,n);
        int Modulo=1000000007;
        long long result=0;
        for(int e=0;e<n;e++){
            long long left=e-NSL[e];
            long long right=NSR[e]-e;
            long long total_ways=left*right;
            long long total_sum=arr[e]*total_ways;
            result=(result+total_sum)%Modulo;
        }
        return result;
    }
};