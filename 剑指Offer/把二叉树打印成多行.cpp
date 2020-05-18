/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
        vector<vector<int> > Print(TreeNode* root) {
            vector<vector<int> > res;
            if(!root)    return res;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                int size = q.size();
                vector<int> tmp;
                for(; size--; q.pop()){
                    TreeNode* node = q.front();
                    if(node->left)    q.push(node->left);
                    if(node->right)    q.push(node->right);
                    tmp.push_back(node->val);
                }
                res.push_back(tmp);
            }
            return res;
        }
    
};