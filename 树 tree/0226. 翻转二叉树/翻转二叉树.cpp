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
    TreeNode* invertTree(TreeNode* root) {
        //�ݹ�
        /*if(root==NULL)
            return root;
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;*/
        //���������ƶ������Ĳ�α���
        if(!root) return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                TreeNode* tmp=q.front();
                q.pop();
                if(tmp)
                {
                    swap(tmp->left,tmp->right);
                    q.push(tmp->left);
                    q.push(tmp->right);
                }
            }
        }
        return root;
    }
};