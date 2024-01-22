class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_set<char> mySet;
        int result=0;
        int left=0;
        for(int e=0;e<n;e++){
            if(mySet.find(s[e])==mySet.end()){
                mySet.insert(s[e]);
                result=max(result,(e-left)+1);
            }else{
                while(mySet.find(s[e])!=mySet.end()){
                    mySet.erase(s[left]);
                    left++;
                }
                mySet.insert(s[e]);
                result=max(result,(e-left)+1);
            }
        }
        return result;
    }
};