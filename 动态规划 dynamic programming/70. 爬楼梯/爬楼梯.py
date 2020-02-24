"""
������������¥�ݡ���Ҫ n?������ܵ���¥����

ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�

ע�⣺���� n ��һ����������

ʾ�� 1��

���룺 2
����� 2
���ͣ� �����ַ�����������¥����
1.  1 �� + 1 ��
2.  2 ��
ʾ�� 2��

���룺 3
����� 3
���ͣ� �����ַ�����������¥����
1.  1 �� + 1 �� + 1 ��
2.  1 �� + 2 ��
3.  2 �� + 1 ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/climbing-stairs
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""

class Solution:
    def climbStairs(self, n: int) -> int:
        if n==1:
            return 1
        elif n==2:
            return 2
        else:
            b = 2
            bb = 1
            for i in range(3,n+1):
                cur = b + bb
                bb = b
                b = cur
            return cur    
			
			
"""
#from functools import lru_cache
class Solution:
    #@lru_cache(10**8)
    def climbStairs(self, n: int) -> int:
        
        if n==1:
            return 1
        elif n==2:
            return 2
        else:
            return self.climbStairs(n-1)+self.climbStairs(n-2)
        
        memory = [0]*(n+1)
        memory[0]=1
        memory[1]=2
        for i in range(2,n):
            memory[i] = memory[i-1]+memory[i-2]
        return memory[n-1]
        
        
"""

"""
from functools import lru_cache
class Solution:
    @lru_cache(10**8)
    def climbStairs(self, n: int) -> int:
        if n==1:
            return 1
        elif n==2:
            return 2
        else:
            return self.climbStairs(n-1)+self.climbStairs(n-2)
"""