"""
����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������

����һ������ÿ�����ݴ�Ž��ķǸ��������飬�������ڲ���������װ�õ�����£��ܹ�͵�Ե�����߽�

ʾ�� 1:

����: [1,2,3,1]
���: 4
����: ͵�� 1 �ŷ��� (��� = 1) ��Ȼ��͵�� 3 �ŷ��� (��� = 3)��
?    ͵�Ե�����߽�� = 1 + 3 = 4 ��
ʾ�� 2:

����: [2,7,9,3,1]
���: 12
����: ͵�� 1 �ŷ��� (��� = 2), ͵�� 3 �ŷ��� (��� = 9)������͵�� 5 �ŷ��� (��� = 1)��
?    ͵�Ե�����߽�� = 2 + 9 + 1 = 12 ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/house-robber
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def rob(self, nums: List[int]) -> int:
        """
        if len(nums)==0:
            return 0
        dp = [[0]*len(nums) for _ in range(2)]
        dp[0][0] = 0
        dp[1][0]= nums[0]
        for i in range(1, len(nums)):
            dp[0][i] = max(dp[0][i-1], dp[1][i-1])
            dp[1][i] = dp[0][i-1] + nums[i]

        return max(dp[0][len(nums)-1], dp[1][len(nums)-1])
        """
        """
        if len(nums)==0:
            return 0
        elif len(nums)==1:
            return nums[0]
        dp = [0]*len(nums)
        dp[0]=nums[0]
        dp[1]=nums[1] if nums[1]>nums[0] else nums[0]
        for i in range(2,len(nums)):
            dp[i]=max(dp[i-1],dp[i-2]+nums[i])
        return dp[len(nums)-1]
        """
        prev = 0
        cur = 0
        for i in range(len(nums)):
            tmp = cur
            cur = max(cur, prev+nums[i])
            prev = tmp
        return cur