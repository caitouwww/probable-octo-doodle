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
    TreeNode* head = NULL;
    TreeNode* pre = NULL;
    TreeNode* Convert(TreeNode* root)
    {
        if(root == NULL)    return NULL;
        inorder(root);
        return head;
    }
    void inorder(TreeNode* root){
        if(root == NULL)    return;
        inorder(root->left);
        if(pre == NULL)    head = pre = root;
        else{
            pre->right = root;
            root->left = pre;
            pre = root;
        }
        inorder(root->right);
    }
};
