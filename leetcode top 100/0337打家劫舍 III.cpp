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
// class Solution {
// public:
//     unordered_map<TreeNode*,int> memo;
//     int rob(TreeNode* root) {
//         return tryRob(root);
//     }
//     int tryRob(TreeNode* root){
//         if(root==nullptr)return 0;
//         if(memo.count(root))return memo[root];
//         //打劫当前节点
//         int robCur = root->val;
//         if(root->left)robCur+=rob(root->left->left)+rob(root->left->right);
//         if(root->right)robCur+=rob(root->right->left)+rob(root->right->right);
//         //不打劫当前节点
//         int unRob = 0;
//         if(root->left)unRob+=rob(root->left);
//         if(root->right)unRob+=rob(root->right);
//         memo[root] = max(robCur,unRob);
//         return memo[root];
//     }
// };

class Solution{
public:
    int rob(TreeNode* root){
        vector<int> res = dp(root);
        return max(res[0], res[1]);
    }
    vector<int> dp(TreeNode* root){
        if(root==nullptr)return vector<int>(2,0);
        vector<int> left = dp(root->left);
        vector<int> right = dp(root->right);
        int rob = root->val + left[0] + right[0];
        int unrob = max(left[0], left[1]) + max(right[0], right[1]);
        return {unrob,rob};
    }
};
