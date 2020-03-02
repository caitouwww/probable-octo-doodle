"""
����һ������ 0, 1, 2, ..., n��n���������У��ҳ� 0 .. n��û�г����������е��Ǹ�����

ʾ��1:

����: [3,0,1]
���: 2
ʾ��2:

����: [9,6,4,2,3,5,7,0,1]
���: 8
˵��:
����㷨Ӧ��������ʱ�临�Ӷȡ����ܷ��ʹ�ö��ⳣ���ռ���ʵ��?

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/missing-number
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        #W1���������ж�
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
        #W2�����з��뼯�ϣ��Ӽ����в��ң����ϲ���Ͳ���ʱ�临�ӶȾ�ΪO(1)��
        """
        nums_set = set(nums)
        for i in range(len(nums_set)+1):
            if i not in nums_set:
                return i
        """
        #W3����������ʣ�һ�������Լ����Ϊ0��[0...n]��nums�е�ֵһһ��򣬵õ���ֵ��Ϊȱʧֵ
        """
        missing = len(nums)
        for index, val in enumerate(nums):
            missing = missing ^ index ^ val
        return missing
        """
        #W4[0...n]�ĺ� �� nums�ĺ� ֮��
        expect_sum = (len(nums)+1)*len(nums) // 2
        actual_sum = sum(nums)
        return expect_sum - actual_sum