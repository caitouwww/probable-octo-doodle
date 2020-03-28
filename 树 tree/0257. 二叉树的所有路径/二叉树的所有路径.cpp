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
    //vector<string> vec;
    //string path;
    vector<string> binaryTreePaths(TreeNode* root) {
        //??
        /*if(!root)
            return vec;
        if(!root->left&&!root->right)
        {
            path+=to_string(root->val);
            vec.push_back(path);
            return vec;
        }
        path+=to_string(root->val)+"->";
        string path2=path;
        binaryTreePaths(root->left);
        path=path2;
        binaryTreePaths(root->right);
        path=path2;
        return vec;*/
        //???,???
        /*vector<string> ans;
        if(root==NULL) return ans;
        TreeNode* p=root;
        stack<pair<TreeNode*,string>> s;
        string str;
        while(!s.empty()||p)
        {
            while(p)
            {
                if(p==root) str+=to_string(p->val);
                else str+="->"+to_string(p->val);
                s.push(pair<TreeNode*,string>(p,str));
                p=p->left;
            }
            p=s.top().first;
            str=s.top().second;
            s.pop();
            if(p->right==NULL&&p->left==NULL) ans.push_back(str);
            p=p->right;
        }
        return ans;*/
        //??
        vector<string> res;
        if(root==NULL)
            return res;
        queue<pair<TreeNode*,string>> q;
        q.push(make_pair(root,to_string(root->val)));
        while(!q.empty())
        {
            TreeNode* node=q.front().first;
            string path=q.front().second;
            q.pop();
            if(node->left==NULL&&node->right==NULL)
                res.push_back(path);
            if(node->left)
                q.push(make_pair(node->left,path+"->"+to_string(node->left->val)));
            if(node->right)
                q.push(make_pair(node->right,path+"->"+to_string(node->right->val)));
        }
        return res;
    }
};