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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root == nullptr) return res;
        bool isLeft = false;
        q.push(root);
        while(!q.empty()){
            vector<int> tmp;
            int size = q.size();
            for(; size--; q.pop()){
                TreeNode* node = q.front();
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
                tmp.push_back(node->val);
            }
            isLeft = !isLeft;
            if(!isLeft) res.push_back(vector<int>(tmp.rbegin(), tmp.rend()));
            else    res.push_back(tmp);
        }
        return res;
    }
};