"""
����һ������ (32 λ�з�������)�����дһ���������ж����Ƿ��� 4?���ݴη���

ʾ�� 1:

����: 16
���: true
ʾ�� 2:

����: 5
���: false
���ף�
���ܲ�ʹ��ѭ�����ߵݹ�����ɱ�����

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/power-of-four
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        """
        if num==0:
            return False
        while num%4==0:
            num = num // 4
        if num==1:
            return True
        else:
            return False
        """
        """
        if num==0:
            return False
        elif num==1:
            return True
        elif num%4==0:
            return self.isPowerOfFour(num//4)
        else:
            return False
        """
        """
        return bin(num).count('1')==1 and num&0x55555555==num
        """
        if num<0 or num&(num-1):
            return False
        return num&0x55555555