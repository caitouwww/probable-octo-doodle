class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int buy = INT_MIN;
        int sell = 0;
        for (int i = 0; i < prices.size(); ++i) {
            // int pre = buy;
            // buy = max(pre, -prices[i]);
            // sell = max(sell, pre + prices[i]);
            sell = max(sell, buy + prices[i]);
            buy = max(buy, -prices[i]);//只能买卖一次
        }
        return sell;
    }
};
