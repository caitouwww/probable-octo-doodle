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
    //�ݹ�
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     inorderTraversal1(root, res);
    //     return res;
    // }
    // void inorderTraversal1(TreeNode* root, vector<int>& res){
    //     if(root == nullptr) return;
    //     inorderTraversal1(root->left, res);
    //     res.push_back(root->val);
    //     inorderTraversal1(root->right, res);
    // }
    //����
    vector<int> inorderTraversal(TreeNode* root){
        // ����������������ֻ�÷ǵݹ飨�ݹ�汾˭�����أ���
        // 1. ջ�󷨡�������ջ���ٷ��ʡ�
        // 2. ��������������ջ������ǰ�������ջ��+��������ջ��������������е���Ŷ����
        vector<int> res;
        stack<TreeNode*> path;
        TreeNode* helper = root;
        while(helper){
            path.push(helper);
            helper = helper->left;
        }
        while(!path.empty()){
            auto node = path.top();
            path.pop();
            res.push_back(node->val);
            node = node->right;
            // ÿ pop һ���ڵ㣬������������**�����ջ**������
            while(node){
                path.push(node);
                node = node->left;
            }
        }
        return res;
    }
};