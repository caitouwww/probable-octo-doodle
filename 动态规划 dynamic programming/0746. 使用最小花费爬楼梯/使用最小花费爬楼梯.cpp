class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(3);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<cost.size();i++)
        {
            dp[i%3]=min(dp[(i-2)%3],dp[(i-1)%3])+cost[i];
        }
        return min(dp[(cost.size()-1)%3],dp[(cost.size()-2)%3]);
    }
};