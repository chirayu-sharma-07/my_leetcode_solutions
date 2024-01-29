class MyQueue {
public:
    vector<int> vec;
    MyQueue() {
        
    }
    
    void push(int x) {
        vec.insert(vec.begin(),x);
    }
    
    int pop() {
        int num=vec[vec.size()-1];
        vec.pop_back();
        return num;
    }
    
    int peek() {
        return vec[vec.size()-1];
    }
    
    bool empty() {
        return vec.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */