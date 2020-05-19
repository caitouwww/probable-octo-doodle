"""
����һ���������� nums���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�

ʾ��:

����: [-2,1,-3,4,-1,2,1,-5,4],
���: 6
����:����������[4,-1,2,1] �ĺ����Ϊ?6��
����:

������Ѿ�ʵ�ָ��Ӷ�Ϊ O(n) �Ľⷨ������ʹ�ø�Ϊ����ķ��η���⡣

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-subarray
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        #������⣬��ʱ
        """
        curmax = float('-inf')
        for i in range(len(nums)):
            for j in range(i+1):
                curmax = max(sum(nums[j:i+1]), curmax)
        return curmax
        """
        #DP��
        #DP״̬ת�Ʒ���
        """
        dp =[0]*len(nums)
        dp[0] = nums[0]
        for i in range(1,len(nums)):
            dp[i] = max(dp[i-1], 0) + nums[i]
        return max(dp)
        """
        #DP��״̬�ռ�ѹ��
        """
        curmax = nums[0]
        wholemax = nums[0]
        for i in range(1, len(nums)):
            curmax = max(curmax, 0) + nums[i]
            wholemax = max(wholemax, curmax)
        return wholemax
        """
        #���η�
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
        
        #��ȡ������е���ʼ�ͽ���λ��
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