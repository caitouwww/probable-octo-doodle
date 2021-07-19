class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s;
        int left = 0, right = 0;
        dfs(s,left,right,n);
        return res;
    }
    void dfs(string s, int left, int right, int n){
        if(left>n||right>left)return;
        if(left==n&&right==n){
            res.push_back(s);
            return;
        }
        dfs(s+'(',left+1,right,n);
        // s.push_back('(');
        // left++;
        // dfs(s,left,right,n);
        // left--;
        // s.pop_back();
        // s.push_back(')');
        // right++;
        // dfs(s,left,right,n);
        // right--;
        // s.pop_back();
        dfs(s+')',left,right+1,n);
    }
private:
    vector<string> res;
};
