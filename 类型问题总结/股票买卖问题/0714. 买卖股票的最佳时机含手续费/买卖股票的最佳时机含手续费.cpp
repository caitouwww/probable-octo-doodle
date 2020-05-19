class Solution {
public:
    Solution(){
        ios::sync_with_stdio(0);
        cin.tie(0);
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        for(int i = 0; i < n; i++){
            int tmp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, dp_i_0 - prices[i] - fee);
        }
        return dp_i_0;
    }
};
