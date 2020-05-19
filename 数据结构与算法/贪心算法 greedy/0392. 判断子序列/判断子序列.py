"""
�����ַ��� s �� t ���ж� s �Ƿ�Ϊ t �������С�

�������Ϊ s �� t �н�����Ӣ��Сд��ĸ���ַ��� t ���ܻ�ܳ������� ~= 500,000������ s �Ǹ����ַ��������� <=100����

�ַ�����һ����������ԭʼ�ַ���ɾ��һЩ��Ҳ���Բ�ɾ�����ַ������ı�ʣ���ַ����λ���γɵ����ַ����������磬"ace"��"abcde"��һ�������У���"aec"���ǣ���

ʾ��1:
s = "abc", t = "ahbgdc"

����true.

ʾ��2:
s = "axc", t = "ahbgdc"

����false.

������ս :

����д�������� S������S1, S2, ... , Sk ���� k >= 10�ڣ�����Ҫ���μ�������Ƿ�Ϊ T �������С�����������£���������ı���룿

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/is-subsequence
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        """
        for i in s:
            if i in t:
                t = t[t.index(i)+1:]
            else:
                return False
        return True
        """
        point_s = 0
        point_t = 0
        len_s = len(s)
        len_t = len(t)
        while point_s < len_s and point_t < len_t:
            if s[point_s]==t[point_t]:
                point_s = point_s + 1
            point_t = point_t + 1
        return point_s == len_s