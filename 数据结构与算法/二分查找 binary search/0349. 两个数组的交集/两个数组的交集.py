"""
�����������飬��дһ���������������ǵĽ�����

ʾ�� 1:

����: nums1 = [1,2,2,1], nums2 = [2,2]
���: [2]
ʾ�� 2:

����: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
���: [9,4]
˵��:

�������е�ÿ��Ԫ��һ����Ψһ�ġ�
���ǿ��Բ�������������˳��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/intersection-of-two-arrays
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def set_intersection(self,nums1,nums2):
            return [x for x in nums1 if x in nums2]
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        #��д
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