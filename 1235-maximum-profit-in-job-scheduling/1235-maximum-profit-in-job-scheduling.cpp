class Solution {
public:

    // Approach One
    // Recursion + Memoization
    // This code gave me TLE :(

    /*
    int n=0;
    int myFunction(int e, vector<int>& startTime, vector<int>& endTime, vector<int> & profit, vector<int> &memo){
        if(e>=n) return 0;
        if(memo[e]!=-1) return memo[e];
        int take=0;
        take=profit[e];
        int end=endTime[e];
        int f=e;
        while(f<n && startTime[f]<end) f++;
        if(f<n){
            take=take+myFunction(f,startTime,endTime,profit,memo);
        }
        int skip=myFunction(e+1,startTime,endTime,profit,memo);
        return memo[e]=max(take,skip);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        vector<vector<int>> vec(n,vector<int>(3));
        for(int e=0;e<n;e++){
            vec[e][0]=startTime[e];
            vec[e][1]=endTime[e];
            vec[e][2]=profit[e];
        }
        sort(vec.begin(),vec.end());
        for(int e=0;e<n;e++){
            startTime[e]=vec[e][0];
            endTime[e]=vec[e][1];
            profit[e]=vec[e][2];
        }
        vector<int> memo(n+1,-1);
        return myFunction(0,startTime,endTime,profit,memo);
    }
    */


    // Approach two
    // Recursion + Memoization + Binary Search
    
    int n=0;
    int binarySearch(vector<vector<int>> &array,int left,int target){
        int right=n-1;
        int result=n+1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(array[mid][0]>=target){
                result=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return result;
    }
    int recursiveFunction(int e,vector<vector<int>> &array,vector<int> &memo){
        if(e>=n) return 0;
        if(memo[e]!=-1) return memo[e];
        int take=array[e][2]+recursiveFunction(binarySearch(array,e+1,array[e][1]),array,memo);
        int skip=recursiveFunction(e+1,array,memo);
        return memo[e]=max(take,skip);
    }
    int jobScheduling(vector<int> &startTime,vector<int> &endTime, vector<int> &profit){
        n=startTime.size();
        if(n==1) return profit[0];
        vector<vector<int>> array(n,vector<int>(3));
        for(int e=0;e<n;e++){
            array[e][0]=startTime[e];
            array[e][1]=endTime[e];
            array[e][2]=profit[e];
        }
        auto myComparator=[&](auto& vec1,auto& vec2){
            return vec1[0]<=vec2[0];
        };
        sort(begin(array),end(array),myComparator);
        vector<int> memo(n,-1);
        return recursiveFunction(0,array,memo);
    }
};