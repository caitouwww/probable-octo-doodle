class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> st;
        int j = 0;
        for(auto x : pushV){
            st.push(x);
            while(j < popV.size() && !st.empty() && st.top() == popV[j]){
                st.pop();
                j++;
            }
        }
        return j == popV.size();
    }
};
