class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.size();
        vector<int> mark(n,0);
        for(int i = 0; i < n; ++i){
            if(s[i]=='(')st.push(i);
            else{
                if(st.empty())mark[i] = 1;
                else{
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            mark[st.top()] = 1;
            st.pop();
        }
        int len = 0;
        int res = 0;
        for(int i = 0; i < n; ++i){
            if(mark[i]){
                len = 0;
                continue;
            }
            len++;
            res = max(res,len);
        }
        return res;
    }
};
