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
    bool HasSubtree(TreeNode* A, TreeNode* B)
    {
        bool res = false;
        if(A != NULL && B != NULL){
            if(A->val == B->val){
                res = doesHasSubTree(A, B);
            }
            if(!res)    res = HasSubtree(A->left, B);
            if(!res)    res = HasSubtree(A->right, B);
        }
        return res;
    }
    bool doesHasSubTree(TreeNode* a, TreeNode* b){
        if(b == NULL)    return true;
        if(a == NULL)    return false;
        if(a->val != b->val)    return false;
        return doesHasSubTree(a->left, b->left) && doesHasSubTree(a->right, b->right);
    }
};
