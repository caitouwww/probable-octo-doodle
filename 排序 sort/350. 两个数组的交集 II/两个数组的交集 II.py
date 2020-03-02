"""
给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [4,9]
说明：

输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
我们可以不考虑输出结果的顺序。
进阶:

如果给定的数组已经排好序呢？你将如何优化你的算法？
如果nums1的大小比nums2小很多，哪种方法更优？
如果nums2的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-arrays-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        """
        res = []
        if len(nums1)<len(nums2):
            nums1,nums2 = nums2,nums1
        for i in range(len(nums2)):
            if nums2[i] in nums1:
                res.append(nums2[i])
                nums1.remove(nums2[i])
        return res
        """
        """
        l = []
        inter = set(nums1)&set(nums2)
        for i in inter:
            l += [i]*min(nums1.count(i),nums2.count(i))
        return l
        """
        from collections import Counter
        return (list((Counter(nums1)&Counter(nums2)).elements()))