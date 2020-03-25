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
    // bool isMirror(TreeNode* p,TreeNode* q)
    // {
    //     if((p==NULL)&&(q==NULL))
    //         return true;
    //     if((p==NULL)||(q==NULL))
    //         return false;
    //     if(p->val!=q->val)
    //         return false;
    //     return isMirror(p->left,q->right)&&isMirror(p->right,q->left);
    // }
    bool check(TreeNode* p,TreeNode*q)
    {
        if((p==NULL)&&(q==NULL))
            return true;
        if((p==NULL)||(q==NULL))
            return false;
        if(p->val!=q->val)
            return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        // return isMirror(root,root);
        /*deque<TreeNode*> tmp;
        tmp.assign({root,root});
        while(tmp.size()!=0)
        {
            TreeNode* p = tmp[tmp.size()-1];
            tmp.pop_back();
            TreeNode* q = tmp[tmp.size()-1];
            tmp.pop_back();

            if(!check(p,q))
            {
                return false;
            }

            if(p!=NULL)
            {
                tmp.push_back(p->left);
                tmp.push_back(q->right);
                tmp.push_back(p->right);
                tmp.push_back(q->left);
            }
        }
        return true;*/
        stack<TreeNode*> s;
        s.push(root);
        s.push(root);
        TreeNode* p;
        TreeNode* q;
        while(!s.empty())
        {
            p=s.top();
            s.pop();
            q=s.top();
            s.pop();
            if(!check(p,q))
            {
                return false;
            }
            if(p!=NULL)
            {
                s.push(p->left);
                s.push(q->right);
                s.push(p->right);
                s.push(q->left);
            }
        }
        return true;
    }
};