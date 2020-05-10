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
    void helper(TreeNode* root, int eN){
        if(root == NULL)    return;
        eN = eN - root->val;
        res2.push_back(root->val);
        if(eN == 0 && root->left == NULL && root->right == NULL){
            res1.push_back(res2);
        }else{
            helper(root->left, eN);
            helper(root->right, eN);
        }
        res2.pop_back();
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        helper(root, expectNumber);
        return res1;
    }
 private:
    vector<vector<int> > res1;
    vector<int> res2;
};
