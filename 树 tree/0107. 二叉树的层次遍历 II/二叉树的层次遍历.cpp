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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<vector<int>> res;
        vector<TreeNode*> stack(1,root);
        while(stack.size()!=0)
        {
            vector<TreeNode*> tmp;
            vector<int> res_each;
            for(auto x:stack)
            {
                res_each.push_back(x->val);
                if(x->left!=NULL)
                    tmp.push_back(x->left);
                if(x->right!=NULL)
                    tmp.push_back(x->right);
            }
            stack=tmp;
            res.insert(res.begin(),res_each);
        } 
        return res;
    }
};
