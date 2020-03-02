"""
����һ�����������������дӸ��ڵ㵽Ҷ�ӽڵ��·����

˵��:Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

ʾ��:

����:

   1
 /   \
2     3
 \
  5

���: ["1->2->5", "1->3"]

����: ���и��ڵ㵽Ҷ�ӽڵ��·��Ϊ: 1->2->5, 1->3

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/binary-tree-paths
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        """
        def construct_path(root, path):
            if root:
                path += str(root.val)
                if not root.left and not root.right:
                    paths.append(path)
                else:
                    path += '->'
                    construct_path(root.left, path)
                    construct_path(root.right, path)
        
        paths = []
        construct_path(root, '')
        return paths
        """
        if not root:
            return []
        paths = []
        stack = [(root, str(root.val))]
        while stack:
            node, path = stack.pop()
            if not node.left and not node.right:
                paths.append(path)
            if node.left:
                stack.append((node.left, path + '->' + str(node.left.val)))
            if node.right:
                stack.append((node.right, path + '->' + str(node.right.val)))
        return paths
