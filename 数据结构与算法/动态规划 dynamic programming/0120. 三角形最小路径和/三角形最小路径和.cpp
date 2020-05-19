class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //自写
        // int size=triangle.size();
        // for(int i=1;i<size;i++)
        // {
        //     int col_size=triangle[i].size();
        //     for(int j=0;j<col_size;j++)
        //     {
        //         if(j==0)    triangle[i][0]=triangle[i][0]+triangle[i-1][0];
        //         else if(j==col_size-1)  triangle[i][j]=triangle[i][j]+triangle[i-1][triangle[i-1].size()-1];
        //         else triangle[i][j]=triangle[i][j]+min(triangle[i-1][j-1],triangle[i-1][j]);
        //     }
        // }
        // int res=INT32_MAX;
        // for(int i=0;i<triangle[size-1].size();i++)
        // {
        //     int tmp=triangle[size-1][i];
        //     if(tmp<res)
        //         res=tmp;
        // }
        // return res;
        //自底向上，DP
        int row=triangle.size();
        vector<int> minlen(row+1,0);
        for(int level=row-1;level>=0;level--)
        {
            for(int i=0;i<=level;i++)
            {
                minlen[i]=min(minlen[i],minlen[i+1])+triangle[level][i];
            }
        }
        return minlen[0];
    }
};