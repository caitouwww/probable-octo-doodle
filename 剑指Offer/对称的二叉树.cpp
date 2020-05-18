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
    bool isSymmetrical(TreeNode* pRoot)
    {
        return isSym(pRoot, pRoot);
    }
    bool isSym(TreeNode* p, TreeNode* q){
        if(p == nullptr && q == nullptr)    return true;
        if(p == nullptr || q == nullptr)    return false;
        if(p->val != q->val)    return false;
        return isSym(p->left, q->right) && isSym(p->right, q->left);
    }

};