class RandomizedSet {
public:

    // First approach
    // Taking O(n) Time complexity for insert and remove

    /*
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
    */


    // Second approach
    // Taking O(n) Time complexity for all the operations
    
    vector<int> vec;
    unordered_map<int,int> myMap;
    int getRandom()
    {
        return vec[rand()%vec.size()];
    }
    bool remove(int val)
    {
        if(myMap[val]==0) return false;
        int index=myMap[val]-1;
        myMap[val]=0;
        if(index<vec.size()-1){
            vec[index]=vec[vec.size()-1];
            myMap[vec[index]]=index+1;
        }
        vec.pop_back();
        return true;
    }
    bool insert(int val)
    {
        if(myMap[val]!=0) return false;
        vec.push_back(val);
        myMap[val]=vec.size();
        return true;
    }
    RandomizedSet()
    {
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */