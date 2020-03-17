"""
���ж�һ�������Ƿ�Ϊ��������

ʾ�� 1:

����: 1->2
���: false
ʾ�� 2:

����: 1->2->2->1
���: true
���ף�
���ܷ���O(n) ʱ�临�ӶȺ� O(1) �ռ临�ӶȽ�����⣿

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/palindrome-linked-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class ListNode:
    def __init__(self, x, y):
        self.val = x
        self.next = y
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        """
        if head is None:
            return True
        
        first_half_end = self.endOfFirstHalf(head)
        second_half_start = self.reverseList(first_half_end.next)

        result = True
        first_pos = head
        second_pos = second_half_start
        while result and second_pos is not None:
            if first_pos.val != second_pos.val:
                result = False
            first_pos = first_pos.next
            second_pos = second_pos.next
        
        first_half_end.next = self.reverseList(second_half_start)
        return result
    def endOfFirstHalf(self, head):
        slow = head
        fast = head
        while fast.next is not None and fast.next.next is not None:
            fast = fast.next.next
            slow = slow.next
        return slow
    def reverseList(self, head):
        prev = None
        cur = head
        while cur is not None:
            nex = cur.next
            cur.next = prev
            prev = cur
            cur = nex
        return prev
        """
        """
        val = []
        cur = head
        while cur is not None:
            val.append(cur.val)
            cur = cur.next
        return val == val[::-1]
        """
        self.front = head
        def recursiveCheck(cur=head):
            if cur is not None:
                if not recursiveCheck(cur.next):
                    return False
                if cur.val!=self.front.val:
                    return False
                self.front = self.front.next
            return True
        return recursiveCheck()