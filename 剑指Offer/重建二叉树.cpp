/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //运行时间：3ms
    //占用内存：584k
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return build(pre, vin, 0, 0, vin.size() - 1);
    }
    TreeNode* build(vector<int>& pre, vector<int>& vin, int root, int start, int end){
        if(start > end)    return NULL;
        TreeNode* tree = new TreeNode(pre[root]);
        int i = start;
        while(i < end && pre[root] != vin[i])    i++;
        tree->left = build(pre, vin, root + 1, start, i - 1);
        tree->right = build(pre, vin, root + 1 + i - start, i + 1, end);
        return tree;
    }
    //不能通过
    /*TreeNode* reConstructBinaryTree(int* preorder, int* inorder, int length){
        if(preorder == nullptr || inorder == nullptr || length <= 0)    return nullptr;
        return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
    }
    TreeNode* ConstructCore
    (
        int* startPreorder, int* endPreorder,
        int* startInorder, int* endInorder
    )
    {
        int rootValue = startPreorder[0];
        TreeNode* root = new TreeNode();
        root->val = rootValue;
        root->left = root->right = nullptr;
        if(startPreorder == endPreorder){
            if(startInorder == endInorder && *startPreorder == *startInorder)    return root;
            else    throw std::exception("Invalid input.");
        }
        int* rootInorder = startInorder;
        while(rootInorder <= endInorder && *rootInorder != rootValue)    ++rootInorder;
        if(rootInorder == endInorder && *rootInorder != rootValue)    throw std::exception("Invalid input.");
        int leftLength = rootInorder - startInorder;
        int* leftPreorderEnd = startPreorder + leftLength;
        if(leftLength > 0){
            root->left = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
        }
        if(leftLength < endPreorder - startPreorder){
            root->right = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
        }
        return root;
    }*/
};
