"""
����һ���������� A������ֻ�������·����޸ĸ����飺����ѡ��ĳ�������� i���� A[i] �滻Ϊ -A[i]��Ȼ���ܹ��ظ�������� K �Ρ������ǿ��Զ��ѡ��ͬһ������ i����

�����ַ�ʽ�޸�����󣬷���������ܵ����͡�



ʾ�� 1��

���룺A = [4,2,3], K = 1
�����5
���ͣ�ѡ������ (1,) ��Ȼ�� A ��Ϊ [4,-2,3]��
ʾ�� 2��

���룺A = [3,-1,0,2], K = 3
�����6
���ͣ�ѡ������ (1, 2, 2) ��Ȼ�� A ��Ϊ [3,1,0,2]��
ʾ�� 3��

���룺A = [2,-3,-1,5,-4], K = 2
�����13
���ͣ�ѡ������ (1, 4) ��Ȼ�� A ��Ϊ [2,3,-1,5,4]��


��ʾ��

1 <= A.length <= 10000
1 <= K <= 10000
-100 <= A[i] <= 100

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximize-sum-of-array-after-k-negations
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        if K==0:
            return sum(A)
        else:
            tmp = min(A)
            index = A.index(tmp)
            A[index] = -A[index]
            return self.largestSumAfterKNegations(A,K-1)