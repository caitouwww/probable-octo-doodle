"""
����һ����������������Ƿ��Ǿ���ԳƵġ�

���磬������?[1,2,2,3,4,4,3] �ǶԳƵġ�

    1
   / \
  2   2
 / \ / \
3  4 4  3
�����������?[1,2,2,null,3,null,3] ���Ǿ���ԳƵ�:

    1
   / \
  2   2
   \   \
   3    3
˵��:

�����������õݹ�͵������ַ������������⣬��ܼӷ֡�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/symmetric-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        """
        def isMirror(p:TreeNode,q:TreeNode):
            if not p and not q:
                return True
            if not p or not q:
                return False
            if p.val!=q.val:
                return False
            return isMirror(p.left,q.right) and isMirror(p.right, q.left)
        return isMirror(root,root)
        """
        def check(p,q):
            if not p and not q:
                return True
            if not p or not q:
                return False
            if p.val!=q.val:
                return False
            return True
        deq = deque([(root,root)])
        while deq:
            p, q = deq.popleft()
            if not check(p,q):
                return False
            
            if p:
                deq.append((p.left, q.right))
                deq.append((p.right, q.left))
        return True

