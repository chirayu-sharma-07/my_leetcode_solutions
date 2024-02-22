class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        // First approach

        /*
        unordered_set<int> mySet;
        int n=trust.size();
        for(int e=0;e<n;e++){
            mySet.insert(trust[e][0]);
        }
        for(int e=0;e<n;e++){
            if(mySet.find(trust[e][1])==mySet.end()) return trust[e][1];
        }
        return -1;
        */

        // Approach two

        /*
        int freq[n+1];
        int m=trust.size();
        for(int e=0;e<m;e++){
            freq[trust[e][1]]++;
        }
        int largest=INT_MIN;
        int largest_index=-1;
        for(int e=0;e<=n;e++){
            if(freq[e]>largest){
                largest=freq[e];
                largest_index=e;
            }
        }
        if(largest!=m-1) return -1;
        return largest_index;
        */

        // Third approach

        /*
        int num=trust[0][1];
        int m=trust.size();
        for(int e=1;e<m;e++){
            if(trust[e][1]!=num) return -1;
        }
        return num;
        */
        
        // Fourth approach
        
        /*
        if(n==1) return 1;
        vector<int> freq1(n+1,0);
        vector<int> freq2(n+1,0);
        int m=trust.size();
        for(int e=0;e<m;e++){
            freq1[trust[e][0]]++;
            freq2[trust[e][1]]++;
        }
        for(int e=0;e<=n;e++){
            if(freq2[e]==n-1 && freq1[e]==0) return e;
        }
        return -1;
        */

        // Fifth approach

        if(n==1) return 1;
        vector<bool> hehe(n+1,false);
        unordered_map<int,int> myMap;
        int m=trust.size();
        for(int e=0;e<m;e++){
            hehe[trust[e][0]]=true;
            myMap[trust[e][1]]++;
        }
        for(auto &e:myMap){
            if(e.second==n-1 && hehe[e.first]==false) return e.first;
        }
        return -1;
    }
};