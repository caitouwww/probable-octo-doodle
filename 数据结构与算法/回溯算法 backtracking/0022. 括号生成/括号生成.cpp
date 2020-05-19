class Solution {
public:
    // vector<string> res;
    // vector<string> generateParenthesis(int n) {
    //     dfs(n, n, "");
    //     return res;
    // }
    // void dfs(int left, int right, string curStr){
    //     if(left == 0 && right == 0){
    //         res.push_back(curStr);
    //         return;
    //     }
    //     if(left > 0)    dfs(left - 1, right, curStr + '(');
    //     if(right > left)    dfs(left, right - 1, curStr + ')');
    // }
    vector<string> generateParenthesis(int n){
        vector<string> res;
        func(res, "", 0, 0, n);
        return res;
    }
    void func(vector<string>& res, string str, int l, int r, int n){
        if(l > n || r > n || r > l) return;
        if(l == n && r == n){
            res.push_back(str);
            return;
        }
        func(res, str + '(', l + 1, r, n);
        func(res, str + ')', l, r + 1, n);
        return;
    }
};
