"""
����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�

˵����

����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����

ʾ�� 1:

����: [2,2,1]
���: 1
ʾ��?2:

����: [4,1,2,1,2]
���: 4

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/single-number
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
		'''
        if nums is None:
            return None
        elif len(nums)==1:
            return nums[0]
        else:
            nums.sort()
            l = len(nums)
            i = 0
            #while i!=l-1:
            #    if nums[i]!=nums[i+1]:
            #        return nums[i]
            #    else:
            #        i = i + 2
            #return nums[l-1]
            for i in range(0,l-1,2):
                if nums[i]!=nums[i+1]:
                    return nums[i]

            return nums[l-1]
		'''
'''�б����
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        no_duplicate_list = []
        for i in nums:
            if i not in no_duplicate_list:
                no_duplicate_list.append(i)
            else:
                no_duplicate_list.remove(i)
        return no_duplicate_list.pop()
'''

'''��ϣ��
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        hash_table = {}
        for i in nums:
            try:
                hash_table.pop(i)
            except:
                hash_table[i] = 1
        return hash_table.popitem()[0]
'''

'''��ѧ
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return 2 * sum(set(nums)) - sum(nums)
'''

'''λ����
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a = 0
        for i in nums:
            a ^= i
        return a
'''