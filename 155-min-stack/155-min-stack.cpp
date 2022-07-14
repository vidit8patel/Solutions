class MinStack {
public:
    stack<int> s, minstack;
    MinStack() {
    }
    void push(int val) {
        s.push(val);
        if(minstack.size()==0 || val <= minstack.top())
            minstack.push(val);
    }
    
    void pop() {
        if(minstack.top() == s.top())
            minstack.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */