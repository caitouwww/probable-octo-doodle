class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        set<char> st;
        int ans=0,i=0,j=0;
        while(i<n&&j<n)
        {
            auto iter=st.find(s[j]);
            if(iter==st.end())
            {
                st.insert(s[j++]);
                ans=max(ans,j-i);
            }
            else
            {
                st.erase(s[i++]);
            }
        }
        return ans;
    }
};