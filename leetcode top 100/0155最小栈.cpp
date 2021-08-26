class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int val) {
        data.push(val);
        if(helper.empty() || val <= helper.top())helper.push(val);
    }
    
    void pop() {
        if(data.top()==helper.top())helper.pop();
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return helper.top();
    }
    stack<int> data;
    stack<int> helper;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
