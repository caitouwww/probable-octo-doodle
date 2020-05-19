class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //����
        /*if(prices.size()==0)
            return 0;
        int profit=0;
        for(int i=0;i<prices.size()-1;i++)
        {
            int sum=-prices[i];
            for(int j=i+1;j<prices.size();j++)
            {
                sum+=prices[j];
                if(sum>profit)
                {
                    profit=sum;
                }
                sum-=prices[j];
            }
        }
        return profit;*/
        //�������Ż�
        /*if(prices.size()==0)
            return 0;
        int minVal=INT_MAX;
        int maxProfit=0;
        for(int i=0;i<prices.size();i++)
        {
            maxProfit=max(maxProfit,prices[i]-minVal);
            minVal=min(minVal,prices[i]);
        }
        return maxProfit;*/
        //̰��
        /*if(prices.size()==0)
            return 0;
        int sum=-prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++)
        {
            sum+=prices[i];
            if(sum>profit)
            {
                profit=sum;
            }
            if(sum<0)
            {
                sum=-prices[i];
            }
            else
                sum-=prices[i];
        }
        return profit;*/
        //dp
        /*vector<vector<int>> dp(prices.size(),vector<int>());
        for(int i=0;i<prices.size();i++)
        {
            dp[i].resize(2);
        }
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        for(int i=1;i<prices.size();i++)
        {
            dp[i][0]=max(dp[i-1][1]+prices[i],dp[i-1][0]);
            dp[i][1]=max(-prices[i],dp[i-1][1]);
            //��Ϊ��Ŀֻ����һ�ν��ף���˲��ܼ��� dp[i - 1][0]��
        }
        return dp[prices.size()-1][0];*/
        //dp[i]ֻ����dp[i-1]��ʹ�ù�������ļ���
        /*if(prices.size()==0)
            return 0;
        vector<vector<int>> dp(2,vector<int>());
        for(int i=0;i<2;i++)
        {
            dp[i].resize(2);
        }
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        for(int i=1;i<prices.size();i++)
        {
            dp[i&1][0]=max(dp[(i-1)&1][0],dp[(i-1)&1][1]+prices[i]);
            dp[i&1][1]=max(dp[(i-1)&1][1],-prices[i]);
        }
        return dp[(prices.size()-1)&1][0];*/
        //ʹ�ò������
        /*if(prices.size()<2)
            return 0;
        vector<int> diff(prices.size()-1,0);
        for(int i=0;i<prices.size()-1;i++)
        {
            diff[i]=prices[i+1]-prices[i];
        }
        vector<int> dp(prices.size()-1,0);
        dp[0]=diff[0];
        int res=0;
        for(int i=1;i<prices.size()-1;i++)
        {
            dp[i]=max(diff[i],dp[i-1]+diff[i]);
        }
        for(int i=0;i<prices.size()-1;i++)
        {
            res=max(res,dp[i]);
        }
        return res;*/
        if(prices.size()<2)
            return 0;
        int res=0,diff=0,cur=0;
        for(int i=1;i<prices.size();i++)
        {
            diff=prices[i]-prices[i-1];
            cur=max(diff,cur+diff);
            res=max(res,cur);
        }
        return res;
    }
};