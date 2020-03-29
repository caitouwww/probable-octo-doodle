class MyQueue {
public:
    // stack<int> s;
    // stack<int> helper;
    stack<int> pushs,pops;
    void push2pop()
    {
        if(pops.empty())
        {
            while(!pushs.empty())
            {
                pops.push(pushs.top());
                pushs.pop();
            }
        }
    }
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        // s.push(x);
        pushs.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // int size=s.size();
        // for(int i=0;i<size;i++)
        // {
        //     helper.push(s.top());
        //     s.pop();
        // }
        // int res=helper.top();
        // helper.pop();
        // size=helper.size();
        // for(int i=0;i<size;i++)
        // {
        //     s.push(helper.top());
        //     helper.pop();
        // }
        // return res;
        push2pop();
        int res=pops.top();
        pops.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        // int size=s.size();
        // for(int i=0;i<size;i++)
        // {
        //     helper.push(s.top());
        //     s.pop();
        // }
        // int res=helper.top();
        // //helper.pop();
        // size=helper.size();
        // for(int i=0;i<size;i++)
        // {
        //     s.push(helper.top());
        //     helper.pop();
        // }
        // return res;
        push2pop();
        return pops.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        // return s.empty();
        return pushs.empty()&&pops.empty();
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