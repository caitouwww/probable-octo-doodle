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
    TreeNode* invertTree(TreeNode* root) {
        //递归
        // if(root==nullptr)return root;
        // TreeNode* l = invertTree(root->left);
        // TreeNode* r = invertTree(root->right);
        // root->left = r;
        // root->right = l;
        // return root;
        //迭代
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto node = q.front();
                q.pop();
                if(node){
                    swap(node->left,node->right);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};
