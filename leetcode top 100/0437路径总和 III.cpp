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
 //递归
// class Solution {
// public:
//     int res = 0;
//     int pathSum(TreeNode* root, int targetSum) {
//         if(root==nullptr)return 0;
//         sumCount(root,targetSum);
//         pathSum(root->left,targetSum);
//         pathSum(root->right,targetSum);
//         return res;
//     }
//     void sumCount(TreeNode* root, int targetSum){
//         if(root==nullptr)return;
//         targetSum-=root->val;
//         if(targetSum==0)res++;
//         sumCount(root->left,targetSum);
//         sumCount(root->right,targetSum);
//     }
// };
//前缀和
class Solution{
public:
    unordered_map<int,int> um;
    int pathSum(TreeNode* root, int targetSum){
        if(root==nullptr)return 0;
        um[0] = 1;
        int target = targetSum;
        return dfs(root,0,target);
    }
    int dfs(TreeNode* root, int presum, int target){
        if(root==nullptr)return 0;
        int res = 0;
        int cursum = presum+root->val;
        res+=um[cursum-target];
        um[cursum]++;
        res+=dfs(root->left,cursum,target)+dfs(root->right,cursum,target);
        um[cursum]--;
        return res;
    }
};
