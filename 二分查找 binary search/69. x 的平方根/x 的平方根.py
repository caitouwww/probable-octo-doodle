"""
ʵ��int sqrt(int x)������

���㲢����x��ƽ����������x �ǷǸ�������

���ڷ������������������ֻ���������Ĳ��֣�С�����ֽ�����ȥ��

ʾ�� 1:

����: 4
���: 2
ʾ�� 2:

����: 8
���: 2
˵��: 8 ��ƽ������ 2.82842..., 
    ���ڷ���������������С�����ֽ�����ȥ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/sqrtx
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
import math as m
class Solution:
    def mySqrt(self, x: int) -> int:
        """
        tx = m.sqrt(x)
        return int(tx)
        """
        xn1 = x
        xn = 0
        while abs(xn1-xn)>=1:
            xn = xn1
            xn1 = xn - (xn*xn - x)/(2*xn)
        return int(xn1)