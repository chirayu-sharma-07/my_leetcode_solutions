class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people),end(people));
        int e=0;
        int f=people.size()-1;
        int result=0;
        while(e<=f){
            if(people[e]+people[f]<=limit){
                e++;
            }
            result++;
            f--;
        }
        return result;
    }
};