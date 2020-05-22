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
    //递归
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     inorderTraversal1(root, res);
    //     return res;
    // }
    // void inorderTraversal1(TreeNode* root, vector<int>& res){
    //     if(root == nullptr) return;
    //     inorderTraversal1(root->left, res);
    //     res.push_back(root->val);
    //     inorderTraversal1(root->right, res);
    // }
    //迭代
    vector<int> inorderTraversal(TreeNode* root){
        // 二叉树遍历，我们只用非递归（递归版本谁不会呢？）
        // 1. 栈后法。即先入栈，再访问。
        // 2. 中序遍历，左臂入栈法。（前序遍历，栈后法+右左孩子入栈法。后序遍历？有点难哦！）
        vector<int> res;
        stack<TreeNode*> path;
        TreeNode* helper = root;
        while(helper){
            path.push(helper);
            helper = helper->left;
        }
        while(!path.empty()){
            auto node = path.top();
            path.pop();
            res.push_back(node->val);
            node = node->right;
            // 每 pop 一个节点，将其右子树做**左臂入栈**操作。
            while(node){
                path.push(node);
                node = node->left;
            }
        }
        return res;
    }
};