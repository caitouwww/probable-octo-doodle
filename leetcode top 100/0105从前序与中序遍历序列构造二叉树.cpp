/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int> index;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); ++i) {
            index[inorder[i]] = i;
        }
        return build(preorder,0,preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* build(vector<int>& preorder, int l1, int r1, vector<int>& inorder, int l2, int r2) {
        if(l1>r1 || l2>r2)return nullptr;
        if(preorder.size() == 1 && inorder.size() == 1) {
            return new TreeNode(preorder[l1]);
        }
        TreeNode* root = new TreeNode(preorder[l1]);
        int i = index[preorder[l1]];
        // int i = l2;
        // while(i <= r2 && inorder[i] != preorder[l1])i++;
        root->left = build(preorder,l1+1,l1+i-l2,inorder,l2,i-1);
        root->right = build(preorder,l1+i-l2+1,r1,inorder,i+1,r2);
        return root;
    }
};
