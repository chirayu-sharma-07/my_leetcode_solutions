class Solution {
public:
    struct PairHash {
    template <class T1, class T2>
    size_t operator () (const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2;
        }
    };
    bool isPathCrossing(string path) {
        unordered_set<pair<int,int>,PairHash> mySet;
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
    }
};