"""
��˾�ƻ����� 2N �ˡ��� i �˷��� A �еķ���Ϊ costs[i][0]������ B �еķ���Ϊ costs[i][1]��

���ؽ�ÿ���˶��ɵ�ĳ�����е���ͷ��ã�Ҫ��ÿ�����ж��� N �˵ִ



ʾ����

���룺[[10,20],[30,200],[400,50],[30,20]]
�����110
���ͣ�
��һ����ȥ A �У�����Ϊ 10��
�ڶ�����ȥ A �У�����Ϊ 30��
��������ȥ B �У�����Ϊ 50��
���ĸ���ȥ B �У�����Ϊ 20��

����ܷ���Ϊ 10 + 30 + 50 + 20 = 110��ÿ�����ж���һ����������ԡ�


��ʾ��

1 <= costs.length <= 100
costs.length Ϊż��
1 <= costs[i][0], costs[i][1] <= 1000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/two-city-scheduling
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        #��д
        """
        lst = []
        res = 0
        for i in range(len(costs)):
            lst.append((costs[i][1]-costs[i][0],i))
        lst.sort(reverse=True)
        for i in range(len(lst)):
            if i<len(lst)//2:
                res = res + costs[lst[i][1]][0]
            else:
                res = res + costs[lst[i][1]][1]
        return res
        """
        costs.sort(key = lambda x: x[0] - x[1])
        total = 0
        l = len(costs) // 2
        for i in range(l):
            total = total + costs[i][0]+costs[i+l][1]
        return total