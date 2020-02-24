"""
����һ���������� nums��������������i��j(i��j) ��Χ��Ԫ�ص��ܺͣ�����i,j���㡣

ʾ����

���� nums = [-2, 0, 3, -5, 2, -1]����ͺ���Ϊ sumRange()

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
˵��:

����Լ������鲻�ɱ䡣
���ε���sumRange������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/range-sum-query-immutable
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class NumArray:
    """
    def __init__(self, nums: List[int]):
        if not nums:
            return
        self.dp = [0]*(len(nums)+1)
        self.dp[1] = nums[0]
        for i in range(2,len(nums)+1):
            self.dp[i] = self.dp[i-1] + nums[i-1]
    def sumRange(self, i: int, j: int) -> int:
        return self.dp[j+1] - self.dp[i]
    """
    def __init__(self, nums):
        if not nums:
            return 
        self.dp = [0]*len(nums)
        self.dp[0] = nums[0]
        for i in range(1, len(nums)):
            self.dp[i] = self.dp[i-1]+nums[i]
    def sumRange(self, i, j):
        if i==0:
            return self.dp[j]
        else:
            return self.dp[j]-self.dp[i-1]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)