"""
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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