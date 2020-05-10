/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        que.push(root);
        if(!root)    return res;
        while(!que.empty()){
            TreeNode* tmp = que.front();
            res.push_back(tmp->val);
            if(tmp->left)    que.push(tmp->left);
            if(tmp->right)    que.push(tmp->right);
            que.pop();
        }
        return res;
    }
};