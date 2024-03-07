class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        // Wrong approach

        /*
        sort(begin(people),end(people));
        int result=0;
        int n=people.size();
        for(int e=0;e<n;e++){
            if(people[e]==limit){
                result++;
                continue;
            }
            if(e<n-1 && people[e]+people[e+1]<=limit){
                result++;
                e++;
                continue;
            }
            result++;
        }
        return result;
        */

        // Second approach

        sort(begin(people),end(people));
        int e=0;
        int f=people.size()-1;
        int result=0;
        while(e<=f){
            if(people[e]+people[f]<=limit){
                e++;
            }
            f--;
            result++;
        }
        return result;
    }
};