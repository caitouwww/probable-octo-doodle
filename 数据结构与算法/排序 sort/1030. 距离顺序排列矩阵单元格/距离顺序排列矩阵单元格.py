"""
���� R �� C �еľ������еĵ�Ԫ�����������Ϊ (r, c)������ 0 <= r < R �� 0 <= c < C��

���⣬�����ڸþ����и�����һ������Ϊ(r0, c0) �ĵ�Ԫ��

���ؾ����е����е�Ԫ������꣬������(r0, c0) �ľ������С������˳���ţ����У�����Ԫ��(r1, c1) �� (r2, c2) ֮��ľ����������پ��룬|r1 - r2| + |c1 - c2|��������԰��κ������������˳�򷵻ش𰸡���



ʾ�� 1��

���룺R = 1, C = 2, r0 = 0, c0 = 0
�����[[0,0],[0,1]]
���ͣ��� (r0, c0) ��������Ԫ��ľ���Ϊ��[0,1]
ʾ�� 2��

���룺R = 2, C = 2, r0 = 0, c0 = 1
�����[[0,1],[0,0],[1,1],[1,0]]
���ͣ��� (r0, c0) ��������Ԫ��ľ���Ϊ��[0,1,1,2]
[[0,1],[1,1],[0,0],[1,0]] Ҳ�ᱻ������ȷ�𰸡�
ʾ�� 3��

���룺R = 2, C = 3, r0 = 1, c0 = 2
�����[[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
���ͣ��� (r0, c0) ��������Ԫ��ľ���Ϊ��[0,1,1,2,2,3]
����������ĿҪ��Ĵ�Ҳ�ᱻ��Ϊ��ȷ������ [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]]��


��ʾ��

1 <= R <= 100
1 <= C <= 100
0 <= r0 < R
0 <= c0 < C

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/matrix-cells-in-distance-order
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        """
        res = []
        for i in range(R):
            for j in range(C):
                res.append((abs(i-r0)+abs(j-c0),[i,j]))
        res.sort()
        return list(x[1] for x in res)
        """
        """
        return sorted([[i,j] for i in range(R) for j in range(C)],key=lambda x:abs(x[0]-r0)+abs(x[1]-c0))
        """
        lst = [[] for i in range(R+C)]
        for i in range(R):
            for j in range(C):
                tmp = abs(i-r0)+abs(j-c0)
                lst[tmp].append([i,j])
        res = []
        for i in lst:
            if i:
                res.extend(i)
            else:
                break
        return res