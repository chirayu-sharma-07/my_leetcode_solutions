/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    stack<NestedInteger> st;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int e=nestedList.size()-1;e>=0;e--){
            st.push(nestedList[e]);
        }
    }
    
    int next() {
        int x=st.top().getInteger();
        st.pop();
        return x;
    }
    
    bool hasNext() {
        if(st.empty()) return false;
        while(!st.empty()){
            NestedInteger x=st.top();
            if(x.isInteger()) return true;
            st.pop();
            vector<NestedInteger> vc=x.getList();
            for(int e=vc.size()-1;e>=0;e--){
                st.push(vc[e]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */