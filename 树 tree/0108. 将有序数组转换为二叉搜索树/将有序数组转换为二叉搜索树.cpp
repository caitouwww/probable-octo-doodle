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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(!nums.size())
            return NULL;
        TreeNode* tn=new TreeNode(nums[nums.size()/2]);
        vector<int> nums1(nums.begin(),nums.begin()+nums.size()/2);
        vector<int> nums2(nums.begin()+nums.size()/2+1,nums.end());
        if(nums1.size())
            tn->left=sortedArrayToBST(nums1);
        if(nums2.size())
            tn->right=sortedArrayToBST(nums2);
        return tn;
    }
};
