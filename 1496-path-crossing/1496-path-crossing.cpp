class Solution {
public:
    // First approach
    // TC :- 100%
    // SC :- 93.92%

    /*
    struct PairHash {
    template <class T1, class T2>
    size_t operator () (const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2;
        }
    };

    */
    bool isPathCrossing(string path) {
     
     /*   unordered_set<pair<int,int>,PairHash> mySet;
        int x=0;
        int y=0;
        int n=path.size();
        mySet.insert({0,0});
        for(int e=0;e<n;e++){
            if(path[e]=='N') y++;
            else if(path[e]=='E') x++;
            else if(path[e]=='W') x--;
            else y--;
            if(mySet.find({x,y})!=mySet.end()) return true;
            mySet.insert({x,y});
        }
        return false;

        */

        // Second approach

        unordered_set<string> s;
        string str="";
        str=to_string(0)+"_"+to_string(0);
        s.insert(str);
        int n=path.size();
        int i=0;
        int j=0;
        for(int e=0;e<n;e++){
            if(path[e]=='N') j++;
            else if(path[e]=='S') j--;
            else if(path[e]=='E') i++;
            else i--;
            str=to_string(i)+'_'+to_string(j);
            if(s.find(str)!=s.end()){
                return true;
            }
            s.insert(str);
        }
        return false;
    }
};