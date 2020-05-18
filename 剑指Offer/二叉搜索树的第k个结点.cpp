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
    int index = 0;
    TreeNode* KthNode(TreeNode* root, int k)
    {
        if(root != nullptr){
            TreeNode* node = KthNode(root->left, k);
            if(node != nullptr)    return node;
            index++;
            if(index == k)    return root;
            node = KthNode(root->right, k);
            if(node != nullptr)    return node;
        }
        return nullptr;
    }
};