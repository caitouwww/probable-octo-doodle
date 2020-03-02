"""
给定一个整数数组 nums，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释:连续子数组[4,-1,2,1] 的和最大，为?6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        #暴力求解，超时
        """
        curmax = float('-inf')
        for i in range(len(nums)):
            for j in range(i+1):
                curmax = max(sum(nums[j:i+1]), curmax)
        return curmax
        """
        #DP法
        #DP状态转移方程
        """
        dp =[0]*len(nums)
        dp[0] = nums[0]
        for i in range(1,len(nums)):
            dp[i] = max(dp[i-1], 0) + nums[i]
        return max(dp)
        """
        #DP加状态空间压缩
        """
        curmax = nums[0]
        wholemax = nums[0]
        for i in range(1, len(nums)):
            curmax = max(curmax, 0) + nums[i]
            wholemax = max(wholemax, curmax)
        return wholemax
        """
        #分治法
        return self.maxSubArrayDivideWithBorder(nums, 0, len(nums)-1)

    def maxSubArrayDivideWithBorder(self, nums, start, end):
        if start==end:
            return nums[start]
        
        center = (start + end) // 2
        leftMax = self.maxSubArrayDivideWithBorder(nums, start, center)
        rightMax = self.maxSubArrayDivideWithBorder(nums, center+1, end)

        leftCrossMax = float('-inf')
        leftCrossSum = 0
        for i in range(center, start-1, -1):
            leftCrossSum = leftCrossSum + nums[i]
            leftCrossMax = max(leftCrossMax, leftCrossSum)
        
        rightCrossMax = float('-inf')
        rightCrossSum = 0
        for i in range(center+1, end+1, 1):
            rightCrossSum = rightCrossSum + nums[i]
            rightCrossMax = max(rightCrossMax, rightCrossSum)

        crossMax = leftCrossMax + rightCrossMax

        return max(leftMax, rightMax, crossMax)
        
        #获取最大序列的起始和结束位置
        """
        def maxSubArrayPos(nums):
            if nums is None:
                return 0
            start = 0
            end = 0
            subStart = 0
            subEnd = 0
            max = nums[0]
            subMax = nums[0]
            for i in range(1, len(nums)):
                if subMax > 0:
                    subMax = subMax + nums[i]
                    subEnd = subEnd + 1
                else:
                    subMax = nums[i]
                    subStart = i
                    subEnd = i
                if subMax > max:
                    max = subMax
                    start = subStart
                    end = subEnd
            return max
        """