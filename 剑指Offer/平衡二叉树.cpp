class Solution {
public:
    int f = 0;
    bool IsBalanced_Solution(TreeNode* pRoot) {
        dfs(pRoot);
        if(f)    return false;
        return true;
    }
    int dfs(TreeNode* root){
        if(root == NULL)    return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if(abs(l - r) > 1) f = 1;
        return max(l, r) + 1;
    }
};