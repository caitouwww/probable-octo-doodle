class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        unordered_set<string> m(wordDict.begin(),wordDict.end());
        dp[0]=true;
        int maxWordLength=0;
        for(int i=0;i<wordDict.size();i++)
        {
            maxWordLength=max(maxWordLength,(int)wordDict[i].size());
        }
        for(int i=1;i<=s.size();i++)
        {
            for(int j=max(i-maxWordLength,0);j<i;j++)
            {
                if(dp[j]&&m.find(s.substr(j,i-j))!=m.end())
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        // for(int i=1;i<=s.size();i++)
        // {
        //     for(int j=0;j<i;j++)
        //     {
        //         if(dp[j]&&m.find(s.substr(j,i-j))!=m.end())
        //         {
        //             dp[i]=true;
        //             break;
        //         }
        //     }
        // }
        return dp[s.size()];
    }
};