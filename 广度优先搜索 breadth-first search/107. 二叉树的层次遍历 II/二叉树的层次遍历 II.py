"""
����һ����������������ڵ�ֵ�Ե����ϵĲ�α����� ��������Ҷ�ӽڵ����ڲ㵽���ڵ����ڵĲ㣬���������ұ�����

���磺
���������� [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
�������Ե����ϵĲ�α���Ϊ��

[
  [15,7],
  [9,20],
  [3]
]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []

        stack = [root] 
        res = []
        while stack:
            tmp = []
            res_each = []
            for i in stack:
                res_each.append(i.val)
                if i.left != None:
                    tmp.append(i.left)
                if i.right != None:
                    tmp.append(i.right)
            stack = tmp
            res.insert(0,res_each)
        
        return res
