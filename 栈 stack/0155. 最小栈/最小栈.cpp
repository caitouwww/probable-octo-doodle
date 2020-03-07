#include <stack>
class MinStack {
public:
    public:
    stack<int> data;
    stack<int> helper;
    MinStack()
    {

    }
    void push(int x)
    {
        data.push(x);
        if(helper.empty()||x<=helper.top()){
            helper.push(x);
        }
        
    }
    void pop()
    {
        if(data.top()==helper.top())
            helper.pop();
        data.pop();
    }
    int top()
    {
        return data.top();
        
    }
    int getMin()
    {
        return helper.top();
    }
};