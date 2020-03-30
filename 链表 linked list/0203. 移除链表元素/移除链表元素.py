"""
ɾ�������е��ڸ���ֵ val �����нڵ㡣

ʾ��:

����: 1->2->6->3->4->5->6, val = 6
���: 1->2->3->4->5
"""
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        if head is None:
            return None
        
        sentinel = ListNode(None)
        sentinel.next = head
        prev = sentinel
        cur = head

        while cur:
            if cur.val == val:
                prev.next = cur.next
            else:
                prev = cur
            cur = cur.next
        
        return sentinel.next