"""
��ʹ�������+ ��-������������a��b֮�͡�

ʾ�� 1:

����: a = 1, b = 2
���: 3
ʾ�� 2:

����: a = -2, b = 3
���: 1

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/sum-of-two-integers
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def getSum(self, a: int, b: int) -> int:
        MASK = 0x100000000
        MAX_INT = 0x7fffffff
        MIN_INT = MAX_INT + 1
        while b!=0:
            carry = (a & b) << 1
            a = (a ^ b) % MASK
            b = carry % MASK
        return a if a <=MAX_INT else ~((a % MIN_INT) ^ MAX_INT)
		
		
class Solution:
    def getSum(self, a: int, b: int) -> int:
        a&=0xffffffff
        b&=0xffffffff
        while b:
            carry = a & b
            a ^= b
            b= (carry<<1) & 0xffffffff
        return a if a < 0x80000000 else ~(a^0xffffffff)
