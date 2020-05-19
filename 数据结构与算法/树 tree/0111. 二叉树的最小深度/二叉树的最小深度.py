"""
����һ�����������ҳ�����С��ȡ�

��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������

˵��:Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

ʾ��:

����������[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
����������С��� 2.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/minimum-depth-of-binary-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root:
            if root.left and root.right:
                return min(self.minDepth(root.left),self.minDepth(root.right))+1
            elif root.left:
                return 1+self.minDepth(root.left)
            elif root.right:
                return 1+self.minDepth(root.right)
            else:
                return 1
        else:
            return 0