"""
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明:叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度3 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#from functools import lru_cache
class Solution:
    #@lru_cache(10**8)
    def maxDepth(self, root: TreeNode) -> int:
        #if not root:
        #    return 0
        """
        if not root.left and not root.right:
            return 1
        if not root.left:
            return 1+self.maxDepth(root.right)
        if not root.right:
            return 1+self.maxDepth(root.left)
        
        return 1+self.maxDepth(root.left)if self.maxDepth(root.left)>self.maxDepth(root.right) else 1+self.maxDepth(root.right)
        """
        #return max(self.maxDepth(root.left),self.maxDepth(root.right))+1
        stack = []
        if root is not None:
            stack.append((1,root))

        depth = 0
        while stack!=[]:
            current_depth, root = stack.pop()
            if root is not None:
                depth = max(current_depth, depth)
                stack.append((current_depth+1, root.left))
                stack.append((current_depth+1, root.right))

        return depth