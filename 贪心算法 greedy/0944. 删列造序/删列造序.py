"""
������N��Сд��ĸ�ַ�����ɵ����� A������ÿ���ַ���������ȡ�

ɾ�� �����Ķ����ǣ�ѡ��һ��Ҫɾ�����У�ɾȥA�ж�Ӧ���е������ַ�����ʽ�ϣ��� n��Ϊ[A[0][n], A[1][n], ..., A[A.length-1][n]]����

���磬��A = ["abcdef", "uvwxyz"]��



Ҫɾ������Ϊ{0, 2, 3}��ɾ���� AΪ["bef", "vyz"]�� A���зֱ�Ϊ["b","v"], ["e","y"], ["f","z"]��



����Ҫѡ��һ��Ҫɾ������D����A ִ��ɾ��������ʹ A ��ʣ���ÿһ�ж��� �ǽ������еģ�Ȼ�����㷵��D.length����С����ֵ��



ʾ�� 1��

���룺["cba", "daf", "ghi"]
�����1
���ͣ�
��ѡ�� D = {1}��ɾ���� A ����Ϊ��["c","d","g"] �� ["a","f","i"]����Ϊ�ǽ������С�
��ѡ�� D = {}����ô A ���� ["b","a","h"] �Ͳ��Ƿǽ��������ˡ�
ʾ�� 2��

���룺["a", "b"]
�����0
���ͣ�D = {}
ʾ�� 3��

���룺["zyx", "wvu", "tsr"]
�����3
���ͣ�D = {0, 1, 2}


��ʾ��

1 <= A.length <= 100
1 <= A[i].length <= 1000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/delete-columns-to-make-sorted
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        """
        res = 0
        for i in range(len(A[0])):
            for j in range(len(A)-1):
                if A[j][i]>A[j+1][i]:
                    res = res + 1
                    break

        return res
        """
        res = 0
        for col in zip(*A):
            if any(col[i] > col[i+1] for i in range(len(col)-1)):
                res = res + 1
        return res