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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* node = root;
        stack<TreeNode*> st;
        while(node){
            st.push(node);
            node = node->left;
        }
        vector<int> res;
        while(!st.empty()){
            auto node = st.top();
            st.pop();
            res.push_back(node->val);
            node = node->right;
            while(node){
                st.push(node);
                node = node->left;
            }
        }
        return res;
    }
};
