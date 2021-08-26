class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //dp
        // vector<int> dp(amount+1,amount+1);
        // dp[0] = 0;
        // for(int i = 0; i < dp.size(); ++i){
        //     for(auto&c:coins){
        //         if(i-c>=0)
        //             dp[i] = min(dp[i],dp[i-c]+1);
        //     }
        // }
        // return dp[amount]==amount+1?-1:dp[amount];
        //完全背包
        // vector<int> dp(amount+1,amount+1);
        // dp[0] = 0;
        // for(auto&c:coins){
        //     for(int i = c; i <= amount; ++i){
        //         dp[i] = min(dp[i],dp[i-c]+1);
        //     }
        // }
        // return dp[amount]==amount+1?-1:dp[amount];
        //dfs
        // sort(coins.begin(),coins.end());
        // vector<int> memo(amount+1,INT_MAX);
        // return dfs(coins,amount,memo);
        //bfs
        if(amount==0)return 0;
        queue<int> q;
        q.push(amount);
        vector<bool> visited(amount+1,false);
        visited[amount] = true;
        int step = 1;
        sort(coins.begin(),coins.end());
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i <size; ++i){
                int cur = q.front();
                q.pop();
                for(auto&c:coins){
                    int next = cur - c;
                    if(next==0)return step;
                    else if(next<0)break;
                    if(!visited[next]){
                        q.push(next);
                        visited[next] = true;
                    }
                    // cout << next << endl;
                }
            }
            step++;
        }
        return -1;
    }
    // int dfs(vector<int>& coins, int amount,vector<int>& memo){
    //     int res = INT_MAX;
    //     if(amount==0)return 0;
    //     if(memo[amount]!=INT_MAX)return memo[amount];
    //     for(auto&c:coins){
    //         if(amount-c<0)break;
    //         int subRes = dfs(coins,amount-c,memo);
    //         if(subRes==-1)continue;
    //         res = min(res,subRes+1);
    //     }
    //     return memo[amount]=(res==INT_MAX?-1:res);
    // }
};
