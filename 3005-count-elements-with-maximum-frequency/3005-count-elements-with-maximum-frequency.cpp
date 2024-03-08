class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {

        // First approach

        /*
        vector<int> freq(101);
        int n=nums.size();
        int result=0;
        for(int e=0;e<n;e++){
            freq[nums[e]]++;
        }
        sort(begin(freq),end(freq));
        n=100;
        nums[0]=freq[n];
        while(n>0 && freq[n]==nums[0]){
            result+=freq[n];
            n--;
        }
        return result;
        */

        // Second approach

        /*
        int result[2]={0,0};
        sort(begin(nums),end(nums));
        int n=nums.size();
        for(int e=0;e<n;){
            int num=nums[e];
            int count=0;
            while(e<n && nums[e]==num){
                e++;
                count++;
            }
            if(result[0]<count){
                result[0]=count;
                result[1]=1;
            }else if(result[0]==count) result[1]++;
        }
        return result[0]*result[1];
        */


        // Third approach
        
        /*
        unordered_map<int,int> myMap;
        int n=nums.size();
        for(int e=0;e<n;e++){
            myMap[nums[e]]++;
        }
        int result=0;
        for(auto &e:myMap){
            if(result<e.second) result=e.second;
        }
        n=0;
        for(auto &e:myMap){
            if(e.second==result) n++;
        }
        return n*result;
        */

        // Fourth approach

        unordered_map<int,int> myMap;
        int result[2]={0,0};
        for(auto &e:nums){
            myMap[e]++;
        }
        for(auto &e:myMap){
            if(e.second>result[0]){
                result[1]=1;
                result[0]=e.second;
            }else if(e.second==result[0]) result[1]++;
        }
        return result[1]*result[0];
    }
};