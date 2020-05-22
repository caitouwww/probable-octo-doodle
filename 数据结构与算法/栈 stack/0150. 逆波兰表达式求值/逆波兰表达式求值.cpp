class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int size = tokens.size();
        for(int i = 0; i < size; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int first = s.top();
                s.pop();
                int second = s.top();
                s.pop();
                if(tokens[i] == "+")    s.push(first + second);
                else if(tokens[i] == "-")   s.push(second - first);
                else if(tokens[i] == "*")   s.push(first * second);
                else if(tokens[i] == "/")   s.push(second / first);
            }else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};