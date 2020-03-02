"""
����һ���Ѱ����������е��������飬�ҵ�������ʹ���������֮�͵���Ŀ������

����Ӧ�÷����������±�ֵ index1 �� index2������ index1����С��index2��

˵��:

���ص��±�ֵ��index1 �� index2�����Ǵ��㿪ʼ�ġ�
����Լ���ÿ������ֻ��ӦΨһ�Ĵ𰸣������㲻�����ظ�ʹ����ͬ��Ԫ�ء�
ʾ��:

����: numbers = [2, 7, 11, 15], target = 9
���: [1,2]
����: 2 �� 7 ֮�͵���Ŀ���� 9 ����� index1 = 1, index2 = 2 ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        if numbers is None:
            return None
        l, r = 0, len(numbers)-1
        while l<r:
            if numbers[l]+numbers[r]==target:
                return [l+1,r+1]
            elif numbers[l]+numbers[r]<target:
                l = l + 1
            else:
                r = r - 1
        return None