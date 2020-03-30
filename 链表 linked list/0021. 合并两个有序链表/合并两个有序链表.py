"""
��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�

ʾ����

���룺1->2->4, 1->3->4
�����1->1->2->3->4->4

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/merge-two-sorted-lists
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ListNode(None)
        c = head
        while l1 and l2:
            if l1.val < l2.val:
                c.next = l1
                l1 = l1.next
            else:
                c.next = l2
                l2 = l2.next
            c = c.next
        c.next = l1 if l1 else l2
        return head.next