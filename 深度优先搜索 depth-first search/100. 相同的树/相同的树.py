"""
������������������дһ�����������������Ƿ���ͬ��

����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�

ʾ��1:

����:       1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

���: true
ʾ��2:

����:      1          1
          /           \
         2             2

        [1,2],     [1,null,2]

���: false
ʾ��3:

����:       1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

���: false

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/same-tree
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
            
        