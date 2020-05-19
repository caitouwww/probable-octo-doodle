class Solution {
public:
    int numTrees(int n) {
        if(n==0)    return 0;
        else if(n==1)   return 1;
        else if(n==2)   return 2;
        vector<int> dp(n+1,0);
        dp[0]=1,dp[1]=1,dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            for(int j=0;j<i;j++)
                dp[i]+=dp[j]*dp[i-j-1];
        }
        return dp[n];
        //��̬�滮

    // ����n���ڵ���ڶ����������ĸ�����G(n)����f(i)Ϊ��iΪ���Ķ����������ĸ���

    // ����:G(n) = f(1) + f(2) + f(3) + f(4) + ... + f(n)

    // nΪ���ڵ㣬��iΪ���ڵ�ʱ�����������ڵ����Ϊ[1,2,3,...,i-1]���������ڵ����Ϊ[i+1,i+2,...n]�����Ե�iΪ���ڵ�ʱ�����������ڵ����Ϊi-1�����������ڵ�Ϊn-i����f(i) = G(i-1)*G(n-i),

    // ������ʽ�ɵ�:G(n) = G(0)*G(n-1)+G(1)*(n-2)+...+G(n-1)*G(0)
    }
};   