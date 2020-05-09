/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> dp(TreeNode* root){
        if(root == NULL)    return vector<int> (2, 0);
        vector<int> left = dp(root->left);
        vector<int> right = dp(root->right);
        int rob = root->val + left[0] + right[0];
        int not_rob = max(left[0], left[1]) + max(right[0], right[1]);
        return vector<int>{not_rob, rob};
    }
    int rob(TreeNode* root) {
        //超时
        // map<TreeNode*, int> m;
        // if(root == NULL)    return 0;
        // if(m.count(root) > 0)   return m[root];
        // int do_it = root->val + (root->left == NULL ? 0 : rob(root->left->left) + rob(root->left->right)) + (root->right == NULL ? 0 : rob(root->right->left) + rob(root->right->right));
        // int not_do = rob(root->left) + rob(root->right);
        // int res = max(do_it, not_do);
        // m[root] = res;
        // return res;
        vector<int> res = dp(root);
        return max(res[0], res[1]);
    }
};
