class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> width(m,vector<int>(n,0));
        int res = INT_MIN;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j]=='1'){
                    if(j==0)width[i][j] = 1;
                    else width[i][j] = width[i][j-1]+1;
                }
                int minWidth = width[i][j];
                for(int k = i;k>=0;--k){
                    int height = i-k+1;
                    minWidth = min(minWidth,width[k][j]);
                    res = max(res,height*minWidth);
                }
            }
        }
        return res;
    }
};
