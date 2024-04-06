class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open_count=0;
        int close_count=0;
        set<int> invalid_indexes;
        vector<int> open_indexes;
        int n=s.size();
        for(int e=0;e<n;e++){
            if(s[e]=='('){
                open_count++;
                open_indexes.push_back(e);
            }else if(s[e]==')'){
                close_count++;
                if(close_count>open_count){
                    invalid_indexes.insert(e);
                    close_count--;
                }
            }
        }
        while(open_count>close_count){
            int num=open_indexes[open_indexes.size()-1];
            open_indexes.pop_back();
            invalid_indexes.insert(num);
            open_count--;
        }
        string result="";
        for(int e=0;e<n;e++){
            if(invalid_indexes.find(e)!=invalid_indexes.end()) continue;
            result+=s[e];
        }
        return result;
    }
};