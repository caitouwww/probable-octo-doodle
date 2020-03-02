"""
����һ�����������ҳ��������ȡ�

�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����

˵��:Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

ʾ����
���������� [3,9,20,null,null,15,7]��

    3
   / \
  9  20
    /  \
   15   7
��������������3 ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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