class Solution {
public:
    void push(int value) {
        st.push(value);
        if(minS.empty() || value < minS.top())    minS.push(value);
    }
    void pop() {
        if(!st.empty()){
            if(minS.top() == st.top())    minS.pop();
            st.pop();
        }
    }
    int top() {
        return st.top();
    }
    int min() {
        return minS.top();
    }
private:
    stack<int> st;
    stack<int> minS;
};