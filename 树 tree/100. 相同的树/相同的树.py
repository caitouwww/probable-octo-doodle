"""
给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例1:

输入:       1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

输出: true
示例2:

输入:      1          1
          /           \
         2             2

        [1,2],     [1,null,2]

输出: false
示例3:

输入:       1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/same-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        def check(p:TreeNode,q:TreeNode):
            if not p and not q:
                return True
            if not p or not q:
                return False
            if p.val != q.val:
                return False
            return True
        
        deq = deque([(p,q),])
        while deq:
            p, q = deq.popleft()

            if not check(p,q):
                return False
            if p:
                deq.append((p.left, q.left))
                deq.append((p.right, q.right))
        
        return True
            
        