"""
����һ�������ж��������Ƿ��л���

Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� -1�����ڸ�������û�л���



ʾ�� 1��

���룺head = [3,2,0,-4], pos = 1
�����true
���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣


ʾ��2��

���룺head = [1,2], pos = 0
�����true
���ͣ���������һ��������β�����ӵ���һ���ڵ㡣


ʾ��3��

���룺head = [1], pos = -1
�����false
���ͣ�������û�л���




���ף�

������ O(1)�������������ڴ�����������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/linked-list-cycle
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if head is None or head.next is None:
            return None

        node1 = head
        node2 = head.next
        while node1!=node2:
            if node2 is None or node2.next is None:
                return False

            node1 = node1.next
            node2 = node2.next.next
        return True