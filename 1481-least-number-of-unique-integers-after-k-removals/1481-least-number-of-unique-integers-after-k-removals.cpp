class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        /*
        int n=arr.size();
        unordered_map<int,int> myMap;
        for(int e=0;e<n;e++){
            myMap[arr[e]]++;
        }
        int num=1;
        while(true){
            for(auto &mp:myMap){
                if(k==0) break;
                if(mp.second<=num && mp.second!=0){
                    mp.second--;
                    k--;
                }
            }
            if(k==0) break;
            num++;
        }
        int result=0;
        for(auto &mp:myMap){
            if(mp.second!=0) result++;
        }
        return result;
        */

        // Second approach

        /*
        unordered_map<int,int> myMap;
        int n=arr.size();
        for(int e=0;e<n;e++) myMap[arr[e]]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int count=0;
        for(auto &mp:myMap){
            count++;
            pq.push(make_pair(mp.second,mp.first));
        }
        while(!pq.empty()){
            int x=pq.top().first;
            pq.pop();
            k-=x;
            if(k==0) return count-1;
            else if(k<0) return count;
            else count--;
        }
        return count;
        */

        // Third approach

        /*
        int n=arr.size();
        unordered_map<int,int> mp;
        for(int e=0;e<n;e++) mp[arr[e]]++;
        vector<int> vec;
        int result=0;
        for(auto &e:mp){
            vec.push_back(e.second);
            result++;
        }
        if(k==0) return result;
        sort(begin(vec),end(vec));
        for(int e=0;e<vec.size();e++){
            k-=vec[e];
            result--;
            if(k==0) return result;
            if(k<0) return result+1;
        }
        return 0;
        */
        
        //Fourth approach
        
        /*
        int n=arr.size();
        unordered_map<int,int> mp;
        for(int e=0;e<n;e++) mp[arr[e]]++;
        priority_queue<int,vector<int>,greater<int>> pq;
        int result=0;
        for(auto &e:mp){
            pq.push(e.second);
            result++;
        }
        while(!pq.empty()){
            k-=pq.top();
            pq.pop();
            result--;
            if(k==0 || k<0){
                return (k<0)?result+1:result;
            }
        }
        return 0;
        */
        
        // Fifth approach
        
        /*
        int n=arr.size();
        vector<int> freq(n+1,0);
        unordered_map<int,int> mp;
        for(int e=0;e<n;e++) mp[arr[e]]++;
        int result=0;
        for(auto &e:mp){
            freq[e.second]++;
            result++;
        }
        if(k==0) return result;
        for(int e=0;e<=n;e++){
            if(freq[e]==0) continue;
            k-=(e*freq[e]);
            result-=freq[e]+k;
            if(k==0) return result;
            if(k<0) return result+freq[e];
        }
        return 0;
        */
        
        // sixth approach
        
        int n=arr.size();
        unordered_map<int,int> mp;
        for(int e=0;e<n;e++) mp[arr[e]]++;
        int y=mp.size();
        vector<int> freq(n+1,0);
        for(auto &e:mp){
            freq[e.second]++;
        }
        for(int e=1;e<=n;e++){
            int x=min(k/e,freq[e]);
            k-=(x*e);
            y-=x;
            if(k<=e) return y;
        }
        return 0;
    }
};