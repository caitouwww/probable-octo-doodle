"""
�������ֱ����� 4 �� LED ����Сʱ��0-11�����ײ��� 6 �� LED ������ӣ�0-59����

ÿ�� LED ����һ�� 0 �� 1�����λ���Ҳࡣ



���磬����Ķ������ֱ��ȡ ��3:25����

����һ���Ǹ����� n����ǰ LED ���ŵ��������������п��ܵ�ʱ�䡣

����:

����: n = 1
����: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]


ע������:

�����˳��û��Ҫ��
Сʱ�������㿪ͷ������ ��01:00���ǲ�����ģ�ӦΪ ��1:00����
���ӱ�������λ����ɣ����ܻ����㿪ͷ������ ��10:2������Ч�ģ�ӦΪ ��10:02����

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/binary-watch
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def readBinaryWatch(self, num: int) -> List[str]:
        """
        res = []
        def count(n):
            res = 0
            while n:
                n = n&(n-1)
                res+=1
            return res
        for i in range(12):
            for j in range(60):
                if count(i)+count(j)==num:
                    if j<10:
                        res.append(str(i)+":"+"0"+str(j))
                    else:
                        res.append(str(i)+":"+str(j))
        return res
        """
        """
        return list("%d:%02d"%(i,j) for j in range(60) for i in range(12) if num==bin(i).count('1')+bin(j).count('1'))
        """
        def count(n):
            res = 0
            while n:
                n = n&(n-1)
                res+=1
            return res
        res = []
        dic = {i:count(i) for i in range(60)}
        for i in range(12):
            for j in range(60):
                if dic[i]+dic[j]==num:
                    if j<10:
                        res.append(str(i)+":"+"0"+str(j))
                    else:
                        res.append(str(i)+":"+str(j))
        return res