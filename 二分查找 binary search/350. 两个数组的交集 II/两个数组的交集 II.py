"""
�����������飬��дһ���������������ǵĽ�����

ʾ�� 1:

����: nums1 = [1,2,2,1], nums2 = [2,2]
���: [2,2]
ʾ�� 2:

����: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
���: [4,9]
˵����

��������ÿ��Ԫ�س��ֵĴ�����Ӧ��Ԫ�������������г��ֵĴ���һ�¡�
���ǿ��Բ�������������˳��
����:

��������������Ѿ��ź����أ��㽫����Ż�����㷨��
���?nums1?�Ĵ�С��?nums2?С�ܶ࣬���ַ������ţ�
���?nums2?��Ԫ�ش洢�ڴ����ϣ������ڴ������޵ģ������㲻��һ�μ������е�Ԫ�ص��ڴ��У������ô�죿

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/intersection-of-two-arrays-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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