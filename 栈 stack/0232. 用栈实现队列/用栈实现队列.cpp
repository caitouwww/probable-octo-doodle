class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> stk;
    stack<int> helper;
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!stk.empty())
        {
            helper.push(stk.top());
            stk.pop();
        }
        stk.push(x);
        while(!helper.empty())
        {
            stk.push(helper.top());
            helper.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = stk.top();
        stk.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        return stk.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk.empty();
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