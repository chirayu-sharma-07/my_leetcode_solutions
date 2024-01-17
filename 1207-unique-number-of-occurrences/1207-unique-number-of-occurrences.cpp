class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(begin(arr),end(arr));
        int n=arr.size();
        unordered_set<int> mySet;
        for(int e=0;e<n;){
            int number=arr[e];
            e++;
            int count=1;
            while(e<n && arr[e]==number){
                count++;
                e++;
            }
            if(mySet.find(count)!=mySet.end()) return false;
            mySet.insert(count);
        }
        return true;
    }
};