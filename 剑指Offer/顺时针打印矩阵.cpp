class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row = matrix.size();
        vector<int> res;
        if(row == 0)    return res;
        int col = matrix[0].size();
        if(row == 1 && col == 0)    return res;
        int pa_r = 0, pa_c = 0;
        int pb_r = 0, pb_c = col - 1;
        int pc_r = row - 1, pc_c = 0;
        int pd_r = row - 1, pd_c = col - 1;
        int cnt = 0;
        int i = 0, j = 0;
        while(cnt < row * col){
            while(i == pa_r && i == pb_r && j >= pa_c && j <= pb_c){
                res.push_back(matrix[i][j++]);
                cnt++;
            }
            i++;
            j--;
            if(pa_r == pc_r)    return res;
            while(i > pb_r && i <= pd_r && j == pb_c && j == pd_c){
                res.push_back(matrix[i++][j]);
                cnt++;
            }
            i--;
            j--;
            if(pa_c == pb_c)    return res;
            while(i == pc_r && i == pd_r && j >= pc_c && j < pd_c){
                res.push_back(matrix[i][j--]);
                cnt++;
            }
            i--;
            j++;
            while(i > pa_r && i < pc_r && j == pa_c && j == pc_c){
                res.push_back(matrix[i--][j]);
                cnt++;
            }
            pa_r++;
            pa_c++;
            pb_r++;
            pb_c--;
            pc_r--;
            pc_c++;
            pd_r--;
            pd_c--;
            i = pa_r;
            j = pa_c;
        }
        return res;
    }
};