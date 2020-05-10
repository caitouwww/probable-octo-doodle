class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }
 
    int pop() {
        //常规解法
        /*if(!stack1.empty()){
            while(!stack1.empty()){
                int tmp = stack1.top();
                stack1.pop();
                stack2.push(tmp);
            }
            int res = stack2.top();
            stack2.pop();
            while(!stack2.empty()){
                int tmp = stack2.top();
                stack2.pop();
                stack1.push(tmp);
            }
            return res;
        }
        else{
            return 0;
        }*/
        /*if(!stack2.empty()){
            int res = stack2.top();
            stack2.pop();
            return res;
        }else{
            if(!stack1.empty()){
                while(!stack1.empty()){
                    stack2.push(stack1.top());
                    stack1.pop();
                }
                int res = stack2.top();
                stack2.pop();
                return res;
            }else{
                return 0;
            }
        }*/
        if(stack2.size() <= 0){
            while(stack1.size() > 0){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if(stack2.size() == 0)    return 0;
        int res = stack2.top();
        stack2.pop();
        return res;
    }
 
private:
    stack<int> stack1;
    stack<int> stack2;
};
