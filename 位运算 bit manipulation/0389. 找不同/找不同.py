"""
���������ַ��� s �� t������ֻ����Сд��ĸ��

�ַ���t���ַ���s������ţ�Ȼ�������λ�����һ����ĸ��

���ҳ��� t �б���ӵ���ĸ��



ʾ��:

���룺
s = "abcd"
t = "abcde"

�����
e

���ͣ�
'e' ���Ǹ�����ӵ���ĸ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/find-the-difference
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        """
        ls = list(s)
        lt = list(t)

        for i in ls:
            lt.remove(i)
        return lt[0]
        """
        #ord�������ַ�תΪascii��ֵ��chr������ascii��ֵתΪ�ַ�
        #map(ord,t)ת���ַ���
        return chr(sum(map(ord,t))-sum(map(ord,s)))