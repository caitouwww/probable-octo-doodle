"""
��תһ�ö�������

ʾ����

���룺

     4
   /   \
  2     7
 / \   / \
1   3 6   9
�����

     4
   /   \
  7     2
 / \   / \
9   6 3   1
��ע:
����������ܵ� Max Howell �� ԭ���� ������ ��

�ȸ裺����90���Ĺ���ʦʹ������д�����(Homebrew)��������ȴ�޷�������ʱ�ڰװ���д����ת����������⣬��̫����ˡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/invert-binary-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from queue import Queue
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        
        if root is None:
            return root
        
        root.left, root.right = root.right, root.left

        self.invertTree(root.left)
        self.invertTree(root.right)

        return root