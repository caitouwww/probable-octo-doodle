class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // if(n==0)return 0;
        // vector<int> sell(n,0);
        // vector<int> buy(n,0);
        // vector<int> cool(n,0);
        // buy[0] = -prices[0];
        // for(int i = 1; i < n; ++i){
        //     buy[i] = max(buy[i-1],cool[i-1]-prices[i]);
        //     sell[i] = max(buy[i-1]+prices[i],sell[i-1]);
        //     // cool[i] = max(buy[i-1],max(sell[i-1],cool[i-1]));
        //     cool[i] = sell[i-1];
        //     // cout << cool[i] << " " << buy[i-1] << " " << sell[i-1] << " " << cool[i-1] <<  endl;
        // }
        // return sell[n-1];

        // if(prices.empty())return 0;
        // int n = prices.size();
        // vector<vector<int>> f(n,vector<int>(3,0));
        // f[0][0] = -prices[0];
        // for(int i = 1; i < n; ++i){
        //     f[i][0] = max(f[i-1][0],f[i-1][2]-prices[i]);//持有
        //     f[i][1] = f[i-1][0] + prices[i];//不持有，处于冷冻期
        //     f[i][2] = max(f[i-1][2], f[i-1][1]);//不持有，不处于冷冻期
        // }
        // return max(f[n-1][1],f[n-1][2]);

        if(prices.empty())return 0;
        int n = prices.size();
        int f0 = -prices[0], f1 = 0, f2 = 0;
        for(int i = 1; i < n; ++i){
            int f00 = f0, f11 = f1, f22 = f2;
            f0 = max(f00,f22-prices[i]);
            f1 = f00+prices[i];
            f2 = max(f22,f11);
        }
        return max(f1,f2);
    }
};
