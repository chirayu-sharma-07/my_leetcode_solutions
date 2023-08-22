class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        sort(hours.begin(),hours.end());
        if(target>hours[hours.size()-1]) return 0;
        if(target<=hours[0]) return hours.size();
        int e=0;
        for(;e<hours.size() && hours[e]<target;e++);
        return hours.size()-e;
    }
};