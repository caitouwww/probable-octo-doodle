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
        //µÝ¹é
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
        //µü´ú
        vector<string> ans;
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
        return ans;
    }
};