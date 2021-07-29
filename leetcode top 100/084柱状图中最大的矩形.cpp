class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(),0);
        heights.push_back(0);
        stack<int> st;
        int res = 0;
        for(int i = 0; i < heights.size(); ++i){
            while(!st.empty()&&heights[i]<heights[st.top()]){
                int cur = heights[st.top()];
                st.pop();
                res = max(res,cur*(i-st.top()-1));
            }
            st.push(i);
        }
        return res;
    }
};
