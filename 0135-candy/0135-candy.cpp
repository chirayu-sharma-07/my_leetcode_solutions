class Solution {
public:
    int candy(vector<int>& ratings) {

        // Approach one
        // TC - O(2N)
        // SC - O(2N)

        /*
        int n=ratings.size();
        vector<int> L2R(n,1);
        vector<int> R2L(n,1);
        for(int e=1;e<n;e++){
            if(ratings[e]>ratings[e-1]){
                L2R[e]=L2R[e-1]+1;
            }
        }
        for(int e=n-2;e>=0;e--){
            if(ratings[e]>ratings[e+1]){
                R2L[e]=R2L[e+1]+1;
            }
        }
        int result=0;
        for(int e=0;e<n;e++){
            result+=(L2R[e]>R2L[e])?L2R[e]:R2L[e];
        }
        return result;
        */

        // Approach two
        // TC - O(2N), SC - O(N)

        /*
        int n=ratings.size();
        vector<int> result_count(n,1);
        for(int e=1;e<n;e++){
            if(ratings[e]>ratings[e-1]) result_count[e]=result_count[e-1]+1;
        }
        for(int e=n-2;e>=0;e--){
            if(ratings[e]>ratings[e+1]){
                result_count[e]=max(result_count[e],result_count[e+1]+1);
            }
        }
        int result=0;
        for(int e=0;e<n;e++) result+=result_count[e];
        return result;
        */

        // Approach three
        // TC - O(N) , SC - O(1)

        int n=ratings.size();
        int result=n;
        int e=1;
        while(e<n){
            if(ratings[e]==ratings[e-1]){
                e++;
                continue;
            }
            int peak=0;
            while(ratings[e]>ratings[e-1]){
                peak++;
                result+=peak;
                e++;
                if(e==n) return result;
            }
            int dip=0;
            while(e<n && ratings[e]<ratings[e-1]){
                dip++;
                result+=dip;
                e++;
            }
            result-=min(peak,dip);
        }
        return result;
    }
};