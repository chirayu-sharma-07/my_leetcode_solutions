class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        for(int e=0;e<n;){
            int integer=arr[e];
            e++;
            int count=1;
            while(e<n && integer==arr[e]){
                count++;e++;
            }
            if(count>=((n/4)+1)) return integer;
        }
        return -1;
    }
};