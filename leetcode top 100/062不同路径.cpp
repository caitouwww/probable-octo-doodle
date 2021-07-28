//超时
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         dfs(0,0,m,n);
//         return res;
//     }
//     void dfs(int x, int y,int m, int n){
//         if(x==m-1&&y==n-1){
//             res++;
//             return;
//         }else if(x>=m||y>=n)return;
//         dfs(x+1,y,m,n);
//         dfs(x,y+1,m,n);
//     }
// private:
//     int res;
// };
class Solution{
public:
    int uniquePaths(int m, int n){
        //dp
        // vector<vector<int>> dp(m,vector<int>(n,0));
        // for(int i = 0; i < m; ++i){
        //     for(int j = 0; j < n; ++j){
        //         if(i==0||j==0)dp[i][j] = 1;
        //         else dp[i][j] = dp[i-1][j]+dp[i][j-1];
        //     }
        // }
        // return dp[m-1][n-1];
        //优化
        // vector<int> cur(n,1);
        // for(int i = 1; i < m; ++i){
        //     for(int j = 1; j < n; ++j)cur[j]+=cur[j-1];
        // }
        // return cur[n-1];
        //直接计算:一定走m+n-2步，取其中min(m-1,n-1)步往下，C(N,M) = C(N,M-1)*(N+1-M)/M;
        int N = m + n - 2;
        int M = m<n?m-1:n-1;
        long ans = 1;
        for(int i = 1; i <= M;++i){
            ans=ans*(N-i+1)/i;
        }
        return ans;
        // int N=m+n-2;
        // int M=m<n?m-1:n-1;
        // //计算 C(N,M)
        // //根据：C(N,M)=C(N,M-1)*M/(N-M+1);
        // long ans=1;
        // for(int i=1;i<=M;i++)
        //     ans=ans*(N-i+1)/i;
        // return ans;
    }
};
