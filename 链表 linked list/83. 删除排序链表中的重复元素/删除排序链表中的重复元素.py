"""
����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�

ʾ��1:

����: 1->1->2
���: 1->2
ʾ��2:

����: 1->1->2->3->3
���: 1->2->3

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        """
        if head==None:
            return None
        elif head.next==None:
            return head
        else:
            result = ListNode(None)
            p = result
        #result = result.next
            while head.next:
                q = head.next
                while q.next and q.val==q.next.val:
                    q=q.next
                head = q
            #result.val=head.val
                p.next=q
                p = p.next
            return result.next
        """
        """
        result = head
        p = result
        while head:
            while head.next and head.val==head.next.val:
                head = head.next
            if head.next:
                head = head.next
                p.next = head
                p = p.next
            else:
                break
        return result
        """
        ans = head
        while head:
            if head.next and head.next.val == head.val:
                head.next=head.next.next
            else:
                head=head.next
        return ans