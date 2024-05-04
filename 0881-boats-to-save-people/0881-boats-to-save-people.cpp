class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people),end(people));
        int result=0;
        for(int e=0,f=people.size()-1;e<=f;){
            if(e!=f && people[e]+people[f]<=limit){
                e++;
            }
            f--;
            result++;
        }
        return result;
    }
};