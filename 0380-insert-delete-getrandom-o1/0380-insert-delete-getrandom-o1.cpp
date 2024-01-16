class RandomizedSet {
public:
    vector<int> vec;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        int n=vec.size();
        for(int e=0;e<n;e++){
            if(vec[e]==val) return false;
        }
        vec.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        int n=vec.size();
        int e=0;
        for(;e<n;e++){
            if(vec[e]==val) break;
        }
        if(e==n) return false;
        vec[e]=vec[n-1];
        vec.pop_back();
        return true;
    }
    
    int getRandom() {
        return vec[rand()%vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */