class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int e=1;
        int f=0;
        while(k!=0 && f<arr.size()){
            if(e!=arr[f]){
                k--;
            }else f++;
            e++;
        }
        if(k!=0) e+=k;
        return e-1;
    }
};