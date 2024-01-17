class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        // Approach one
        
        /*
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
        */


        // Approach two

        /*
        int n=arr.size();
        unordered_map<int,int> myMap;
        for(int e=0;e<n;e++){
            myMap[arr[e]]++;
            arr[e]=0;
        }
        int e=0;
        for(auto &mp:myMap){
            arr[e]=mp.second;
            e++;
        }
        sort(begin(arr),end(arr));
        e=0;
        while(arr[e]==0) e++;
        for(;e<n-1;e++){
            if(arr[e]==arr[e+1]) return false;
        }
        return true;
        */

        // Approach three

        int n=arr.size();
        unordered_map<int,int> myMap;
        int e=0;
        for(;e<n;e++){
            myMap[arr[e]]++;
        }
        n=myMap.size();
        vector<int> myArray(n);
        e=0;
        for(auto &mp:myMap){
            myArray[e]=mp.second;
            e++;
        }
        sort(begin(myArray),end(myArray));
        for(e=0;e<n-1;e++){
            if(myArray[e]==myArray[e+1]) return false;
        }
        return true;
    }
};