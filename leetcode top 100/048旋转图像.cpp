class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //先上下翻转，再对角翻转
        // int n = matrix.size();
        // for(int i = 0; i < n/2; ++i)matrix[i].swap(matrix[n-1-i]);
        // for(int i = 0; i < n; ++i){
        //     for(int j = i; j < n; ++j){
        //         swap(matrix[i][j],matrix[j][i]);
        //     }
        // }
        //先对角翻转，再左右翻转
        int n = matrix.size();
        for(int i = 0; i < n; ++i){
            for(int j = i; j < n; ++j){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(auto&row:matrix)reverse(row.begin(),row.end());
    }
};
