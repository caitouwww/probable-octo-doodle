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
    int maxDepth(TreeNode* root) {
        //µÝ¹é
        /*if(root==NULL)
            return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;*/
        //µü´ú£¬BFS
        /*if(root==NULL)  return 0;
        deque<TreeNode*> q;
        q.push_back(root);
        int depth=0;
        while(!q.empty())
        {
            depth++;
            int num=q.size();
            for(int i=1;i<=num;i++)
            {
                TreeNode* p=q.front();
                q.pop_front();
                if(p->left) q.push_back(p->left);
                if(p->right) q.push_back(p->right);
            }
        }
        return depth;*/
        //DFS£¬Õ»µÄÑ­»·°æ
        if(root==NULL) return 0;
        stack<pair<TreeNode*,int>> s;
        TreeNode* p=root;
        int maxDepth=0,depth=0;
        while(!s.empty()||p!=NULL)
        {
            while(p!=NULL)
            {
                s.push(pair<TreeNode*,int>(p,++depth));
                p=p->left;
            }
            p=s.top().first;
            depth=s.top().second;
            if(maxDepth<depth) maxDepth=depth;
            s.pop();
            p=p->right;
        }
        return maxDepth;
    }
};