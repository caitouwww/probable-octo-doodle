"""
�����������飬arr1��arr2��

arr2�е�Ԫ�ظ�����ͬ
arr2�е�ÿ��Ԫ�ض�������arr1��
�� arr1�е�Ԫ�ؽ�������ʹarr1��������˳���arr2�е����˳����ͬ��δ��arr2�г��ֹ���Ԫ����Ҫ�����������arr1��ĩβ��



ʾ����

���룺arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
�����[2,2,2,1,4,3,3,9,6,7,19]


��ʾ��

arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
arr2�е�Ԫ��arr2[i]������ͬ
arr2�е�ÿ��Ԫ��arr2[i]��������arr1��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/relative-sort-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        """
        dic = {}
        res2 = []
        for i in arr2:
            dic[i] = 0
        for i in arr1:
            if i in dic.keys():
                dic[i] = dic[i] + 1
            else:
                res2.append(i)
        res2.sort()
        res = [i  for i in dic.keys() for j in range(dic[i])]
        res = res + res2
        return res
        """
        arr2 += sorted(set(arr1)-set(arr2))
        arr1.sort(key=arr2.index)
        return arr1