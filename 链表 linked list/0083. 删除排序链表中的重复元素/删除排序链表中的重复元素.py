"""
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例1:

输入: 1->1->2
输出: 1->2
示例2:

输入: 1->1->2->3->3
输出: 1->2->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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