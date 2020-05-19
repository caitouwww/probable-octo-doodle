class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        dfs(tmp, n, k, 0);
        return res;
    }
    void dfs(vector<int>& tmp, int n, int k, int start){
        if(tmp.size() == k){
            res.push_back(tmp);
            return;
        }else{
            for(int i = start + 1; i <= n; i++){
                tmp.push_back(i);
                dfs(tmp, n, k, i);
                tmp.pop_back();
            }
        }
    }
};
