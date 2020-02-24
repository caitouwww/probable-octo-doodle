"""
给定两个没有重复元素的数组nums1 和nums2，其中nums1是nums2的子集。找到nums1中每个元素在nums2中的下一个比其大的值。

nums1中数字x的下一个更大元素是指x在nums2中对应位置的右边的第一个比x大的元素。如果不存在，对应位置输出-1。

示例 1:

输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
    对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
    对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
    对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。
示例 2:

输入: nums1 = [2,4], nums2 = [1,2,3,4].
输出: [3,-1]
解释:
    对于num1中的数字2，第二个数组中的下一个较大数字是3。
    对于num1中的数字4，第二个数组中没有下一个更大的数字，因此输出 -1。
注意:

nums1和nums2中所有元素是唯一的。
nums1和nums2的数组大小都不超过1000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-greater-element-i
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        """
        l1 = len(nums1)
        l2 = len(nums2)
        res = [0]*l1
        for i in range(l1):
            j = nums2.index(nums1[i]) + 1
            #start = j
            while j<l2:
                if nums2[j]<=nums1[i]:
                    j = j + 1
                else:
                    res[i] = nums2[j]
                    break
            if j==l2:
                res[i] = -1
        return res
        """
        """
        stack = []
        hash = {}
        if len(nums1)==0:
            return []
        elif len(nums1)==1:
            return [-1]
        else:
            stack.append(nums2[0])
            for i in range(1,len(nums2)):
                if nums2[i]<=stack[-1]:
                    stack.append(nums2[i])
                else:
                    while stack[-1]<nums2[i]:
                        hash[stack[-1]] = nums2[i]
                        stack.pop()
                        if len(stack)==0:
                            break
                    stack.append(nums2[i])
            while len(stack)!=0:
                hash[stack[-1]]=-1
                stack.pop()
            res = []
            for i in nums1:
                res.append(hash[i])
            return res
            """
        #单调栈
        hasha = {}
        stack = []
        for i in range(len(nums2)-1,-1,-1):
            while len(stack)!=0 and stack[-1]<=nums2[i]:
                stack.pop()
            if len(stack)==0:
                hasha[nums2[i]]=-1
            else:
                hasha[nums2[i]]=stack[-1]
            stack.append(nums2[i])

        res = []
        for i in nums1:
            res.append(hasha[i])
        return res