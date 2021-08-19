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
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        getMax(root);
        return res;
    }
    int getMax(TreeNode* root){
        if(root==nullptr)return 0;
        int left = max(getMax(root->left),0);
        int right = max(getMax(root->right),0);
        res = max(res,left+right+root->val);
        return max(left,right)+root->val;
    }
};
