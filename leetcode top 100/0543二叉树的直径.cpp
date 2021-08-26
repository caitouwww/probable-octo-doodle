/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)return 0;
        dfs(root);
        return res;
    }
    int dfs(TreeNode* root){
        if(root==nullptr)return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        res = max(res,left+right);
        return max(left,right)+1;
    }
};
