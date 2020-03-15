class Solution {
public:
    int climbStairs(int n) {
        //动态规划
        /*if(n==1)
            return 1;
        vector<int> dp(n);
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n-1];*/
        //暴力法，超时
        //return climb_staris(0,n);
        //记忆化递归
        /*vector<int> res(n,0);
        return climb_Staris(0,n,res);*/
    }
    /*int climb_Staris(int start,int end,vector<int>& res)
    {
        if(start>end)
            return 0;
        if(start==end)
            return 1;
        if(res[start]>0)
            return res[start];
        res[start]=climb_Staris(start+1,end,res)+climb_Staris(start+2,end,res);
        return res[start];
    }*/
    /*int climb_staris(int start,int end)
    {
        if(start>end)
            return 0;
        if(start==end)
            return 1;
        return climb_staris(start+1,end)+climb_staris(start+2,end);
    }*/
};