class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1,false);
        dp[0] = true;
        for(int i = 1; i <= s.size(); ++i){
            for(auto&w:wordDict){
                int size = w.size();
                if(i>=size&&s.substr(i-size,size)==w)dp[i] = dp[i] || dp[i-size];
            }
        }
        return dp[s.size()];
    }
};
