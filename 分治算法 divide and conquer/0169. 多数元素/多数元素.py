"""
����һ����СΪ n �����飬�ҵ����еĶ���Ԫ�ء�����Ԫ����ָ�������г��ִ�������?? n/2 ??��Ԫ�ء�

����Լ��������Ƿǿյģ����Ҹ������������Ǵ��ڶ���Ԫ�ء�

ʾ��?1:

����: [3,2,3]
���: 3
ʾ��?2:

����: [2,2,1,1,1,2,2]
���: 2

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/majority-element
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        #n = len(nums)
        #mid = n//2
        """
        dic = {}
        for i in nums:
            if i in dic.keys():
                dic[i]=dic[i]+1
            else:
                dic[i]=1
        for i,j in dic.items():
            if j==max(dic.values()):
                return i
        """
        cnt, res = 1, nums[0]
        for i in range(1,len(nums)):
            if res==nums[i]:
                cnt = cnt + 1
            else:
                cnt = cnt - 1
                if cnt == 0:
                    res = nums[i+1]
        return res