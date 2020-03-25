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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //递归
        if(p==NULL&&q==NULL)
        {
            return true;
        }
        else if(p==NULL||q==NULL)
        {
            return false;
        }
        else
        {
            if(p->val!=q->val)
                return false;
            else
                return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        }
        //迭代
        stack<TreeNode*> s;
        s.push(p);
        s.push(q);
        TreeNode* p_tmp;
        TreeNode* q_tmp;
        while(!s.empty())
        {
            q_tmp=s.top();
            s.pop();
            p_tmp=s.top();
            s.pop();
            if(q_tmp==NULL&&p_tmp==NULL) continue;
            else if(q_tmp==NULL&&p_tmp!=NULL) return false;
            else if(q_tmp!=NULL&&p_tmp==NULL) return false;
            else if(q_tmp->val!=p_tmp->val) return false;
            else
            {
                s.push(p_tmp->left);
                s.push(q_tmp->left);
                s.push(p_tmp->right);
                s.push(q_tmp->right);
            }
        }
    }
};