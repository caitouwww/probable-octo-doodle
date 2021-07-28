class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i = 0; i <= m; ++i)dp[i][0] = i;
        for(int i = 0; i <= n; ++i)dp[0][i] = i;
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                int left = dp[i-1][j]+1;
                int down = dp[i][j-1]+1;
                int leftDown = dp[i-1][j-1];
                if(word1[i-1]!=word2[j-1])leftDown+=1;
                dp[i][j] = min(min(leftDown,left),down);
            }
        }
        return dp[m][n];
    }
};
