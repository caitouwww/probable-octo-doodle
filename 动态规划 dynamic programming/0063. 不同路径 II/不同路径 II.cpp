class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //直接在原数组上操作会溢出，另外开辟long类型的数组
        //dp
        // int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        // vector<vector<long>> dp(m,vector<long>(n));
        // for(int i=0;i<m;i++)
        // {
        //     if(obstacleGrid[i][0]==1)
        //     {
        //         int j=i;
        //         while(j<m)
        //         {
        //             dp[j++][0]=0;
        //         }
        //         break;
        //     }
        //     else
        //     {
        //         dp[i][0]=1;
        //     }
        // }
        // for(int j=0;j<n;j++)
        // {
        //     if(obstacleGrid[0][j]==1)
        //     {
        //         int i=j;
        //         while(i<n)
        //         {
        //             dp[0][i++]=0;
        //         }
        //         break;
        //     }
        //     else
        //     {
        //         dp[0][j]=1;
        //     }
        // }
        // for(int i=1;i<m;i++)
        // {
        //     for(int j=1;j<n;j++)
        //     {
        //         if(obstacleGrid[i][j]==1)
        //             dp[i][j]=0;
        //         else
        //             dp[i][j]=dp[i-1][j]+dp[i][j-1];
        //     }
        // }
        // return (int)dp[m-1][n-1];
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)
            return 0;
        obstacleGrid[0][0]=1;
        for(int i=1;i<m;i++)
        {
            obstacleGrid[i][0]=(obstacleGrid[i][0]==0&&obstacleGrid[i-1][0]==1)?1:0;
        }
        for(int i=1;i<n;i++)
        {
            obstacleGrid[0][i]=(obstacleGrid[0][i]==0&&obstacleGrid[0][i-1]==1)?1:0;
        }
        // int i=1;
        // while((i<m)&&(obstacleGrid[i][0]==0))
        //     obstacleGrid[i++][0]=1;
        // while(i<m)
        //     obstacleGrid[i++][0]=0;
        // i=0;
        // while((i<n)&&(obstacleGrid[0][i]==0))
        //     obstacleGrid[0][i++]=1;
        // while(i<n)
        //     obstacleGrid[0][i++]=0;
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j]==1)
                    obstacleGrid[i][j]=0;
                else
                    obstacleGrid[i][j]=obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
            }
        }
        return obstacleGrid[m-1][n-1];
    }
};