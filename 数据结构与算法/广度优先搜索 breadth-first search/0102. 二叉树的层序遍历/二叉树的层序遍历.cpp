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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //经典实现，层序遍历一般来说确实是用队列实现的
        // vector<vector<int> > res;
        // if(root == nullptr) return res;
        // queue<TreeNode*> q;
        // q.push(root);
        // while(!q.empty()){
        //     int size = q.size();
        //     vector<int> tmp;
        //     for(; size--; q.pop()){
        //         TreeNode* node = q.front();
        //         tmp.push_back(node->val);
        //         if(node->left)  q.push(node->left);
        //         if(node->right) q.push(node->right);
        //     }
        //     res.push_back(tmp);
        // }
        // return res;
        //
        // 层序遍历一般来说确实是用队列实现的，但是这里很明显用递归前序遍历就能实现呀，而且复杂度O(n)。。。

        // 要点有几个：

        // 利用depth变量记录当前在第几层（从0开始），进入下层时depth + 1；
        // 如果depth >= vector.size()说明这一层还没来过，这是第一次来，所以得扩容咯；
        // 因为是前序遍历，中-左-右，对于每一层来说，左边的肯定比右边先被遍历到，实际上后序中序都是一样的。。。
        vector<vector<int>> ans;
        pre(root, 0, ans);
        return ans;
    }
    void pre(TreeNode* root, int depth, vector<vector<int>>& ans){
        if(!root) return;
        if(depth >= ans.size())
            ans.push_back(vector<int>{});
        ans[depth].push_back(root->val);
        pre(root->left, depth + 1, ans);
        pre(root->right, depth + 1, ans);
    }
};