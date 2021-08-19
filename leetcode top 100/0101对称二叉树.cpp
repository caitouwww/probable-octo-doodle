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
/*class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root,root);
    }
    bool isSymmetric(TreeNode* nodea,TreeNode* nodeb){
        if(nodea==nullptr&&nodeb==nullptr)return true;
        if(nodea==nullptr||nodeb==nullptr)return false;
        if(nodea->val!=nodeb->val)return false;
        return isSymmetric(nodea->left,nodeb->right)&&isSymmetric(nodea->right,nodeb->left);
    }
};*/
class Solution{
public:
    bool isSymmetric(TreeNode*root){
        stack<TreeNode*> st;
        st.push(root);
        st.push(root);
        while(!st.empty()){
            auto p = st.top();
            st.pop();
            auto q = st.top();
            st.pop();
            if(!check(p,q))return false;
            if(p){
                st.push(p->left);
                st.push(q->right);
                st.push(p->right);
                st.push(q->left);
            }
        }
        return true;
    }
    bool check(TreeNode*p,TreeNode*q){
        if(p==nullptr&&q==nullptr)return true;
        if(p==nullptr||q==nullptr)return false;
        return p->val==q->val;
    }
};
