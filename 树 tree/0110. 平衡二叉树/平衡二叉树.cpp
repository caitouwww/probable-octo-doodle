/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*class Solution {
public:
    vector<int> balance(TreeNode* root)
    {
        if(!root) return {1,0};
        auto l=balance(root->left);
        auto r=balance(root->right);
        return {l[0]&&r[0]&&abs(l[1]-r[1])<=1,max(l[1],r[1])+1};
    }
    bool isBalanced(TreeNode* root) {
        return balance(root)[0];
    }
};*/
class Solution{
public:
    int f=0;
    int dfs(TreeNode* root)
    {
        if(!root) return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        if(abs(l-r)>1) f=1;
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root)
    {
        dfs(root);
        if(f) return false;
        return true;
    }
};