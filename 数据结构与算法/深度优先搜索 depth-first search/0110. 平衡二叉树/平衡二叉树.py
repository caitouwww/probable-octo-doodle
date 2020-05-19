"""
����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������

�����У�һ�ø߶�ƽ�����������Ϊ��

һ��������ÿ���ڵ���������������ĸ߶Ȳ�ľ���ֵ������1��

ʾ�� 1:

���������� [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
����true ��

ʾ�� 2:

���������� [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
����false ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/balanced-binary-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        
        def depth(root):
            if not root:
                return 0
            left = depth(root.left)
            if left == -1:
                return -1
            right = depth(root.right)
            if right == -1:
                return -1
            return max(left, right)+1 if abs(left-right)<2 else -1
        return depth(root) != -1