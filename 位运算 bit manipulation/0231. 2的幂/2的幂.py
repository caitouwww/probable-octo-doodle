"""
����һ����������дһ���������ж����Ƿ��� 2 ���ݴη���

ʾ��1:

����: 1
���: true
����: 20= 1
ʾ�� 2:

����: 16
���: true
����: 24= 16
ʾ�� 3:

����: 218
���: false

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/power-of-two
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        """
        if n <= 0:
            return False 
        elif n == 1:
            return True
        else:
            while n>=2:
                if n %2 != 0:
                    return False
                else:
                    n = n // 2
        return True
        """
        return n>0 and not n&n-1