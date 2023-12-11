class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int occurance=n/4;
        n-=occurance;
        for(int e=0;e<n;e++){
            if(arr[e]==arr[e+occurance]) return arr[e];
        }
        return -1;
    }
};