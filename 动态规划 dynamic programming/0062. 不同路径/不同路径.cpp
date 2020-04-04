class Solution {
public:
    int uniquePaths(int m, int n) {
        //����C(N,M)
        //���ݣ�C(N,M)=C(N,M-1)*(N-M+1)/M
        // int N=m+n-2;
        // int M=m<n?m-1:n-1;
        // long ans=1;
        // for(int i=1;i<=M;i++)
        // {
        //     ans=ans*(N-i+1)/i;
        // }
        // return ans;
        // int N=m+n-2;
        // int M=m<n?m-1:n-1;
        // //���� C(N,M)
        // //���ݣ�C(N,M)=C(N,M-1)*M/(N-M+1);
        // long ans=1;
        // for(int i=1;i<=M;i++)
        //     ans=ans*(N-i+1)/i;
        // return ans;
        //dp��̬�滮
        // vector<vector<int>> dp(m,vector<int>(n));
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(i==0||j==0)
        //             dp[i][j]=1;
        //         else
        //             dp[i][j]=dp[i][j-1]+dp[i-1][j];
        //     }
        // }
        // return dp[m-1][n-1];
        //�Ż�һ���ռ临�Ӷ�O(2n)
        // vector<int> pre(n,1);
        // vector<int> cur(n,1);
        // for(int i=1;i<m;i++)
        // {
        //     for(int j=1;j<n;j++)
        //     {
        //         cur[j]=cur[j-1]+pre[j];
        //     }
        //     pre=cur;
        // }
        // return pre[n-1];
        //�Ż������ռ临�Ӷ�O(n)
        vector<int> cur(n,1);
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                cur[j]+=cur[j-1];
            }
        }
        return cur[n-1];
    }
};