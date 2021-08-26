class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // stack<int> st;
        // for(int i = 0; i < temperatures.size(); ++i){
        //     while(!st.empty()&&temperatures[i]>temperatures[st.top()]){
        //         temperatures[st.top()] = i-st.top();
        //         st.pop();
        //     }
        //     st.push(i);
        // }
        // while(!st.empty()){
        //     temperatures[st.top()] = 0;
        //     st.pop();
        // }
        // return temperatures;
        vector<int> T = temperatures;
        vector<int> res(T.size(),0);
        stack<int> st;
        for(int i = 0; i < T.size(); ++i){
            while(!st.empty() && T[st.top()] < T[i]){
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
