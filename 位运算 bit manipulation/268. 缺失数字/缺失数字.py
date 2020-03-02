"""
给定一个包含 0, 1, 2, ..., n中n个数的序列，找出 0 .. n中没有出现在序列中的那个数。

示例1:

输入: [3,0,1]
输出: 2
示例2:

输入: [9,6,4,2,3,5,7,0,1]
输出: 8
说明:
你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/missing-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        #W1先排序，再判断
        """
        nums.sort()
        if nums[0]==0:
            if len(nums)==1:
                return 1
            else:
                for i in range(1, len(nums)):
                    if nums[i]!=nums[i-1]+1:
                        return nums[i-1]+1
                if nums[i]!=len(nums):
                    return len(nums)
        else:
            return 0
        """
        #W2将序列放入集合，从集合中查找（集合插入和查找时间复杂度均为O(1)）
        """
        nums_set = set(nums)
        for i in range(len(nums_set)+1):
            if i not in nums_set:
                return i
        """
        #W3利用异或性质，一个数与自己亦或为0，[0...n]与nums中的值一一异或，得到的值即为缺失值
        """
        missing = len(nums)
        for index, val in enumerate(nums):
            missing = missing ^ index ^ val
        return missing
        """
        #W4[0...n]的和 与 nums的和 之差
        expect_sum = (len(nums)+1)*len(nums) // 2
        actual_sum = sum(nums)
        return expect_sum - actual_sum