"""
给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [9,4]
说明:

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
class Solution:
    def set_intersection(self,nums1,nums2):
            return [x for x in nums1 if x in nums2]
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        #自写
        """
        res = []
        if len(nums2)>len(nums1):
            nums1,nums2=nums2,nums1
        for i in range(len(nums2)):
            if nums2[i] in nums1 and nums2[i] not in res:
                res.append(nums2[i])
        return res
        """
        """
        return list(set(nums1)&set(nums2))
        """
        set1 = set(nums1)
        set2 = set(nums2)
        if len(set1)<len(set2):
            return self.set_intersection(set1,set2)
        else:
            return self.set_intersection(set2,set1)