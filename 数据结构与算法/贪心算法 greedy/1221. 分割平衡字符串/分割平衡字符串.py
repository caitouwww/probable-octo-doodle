"""
��һ����ƽ���ַ������У�'L' �� 'R' �ַ�����������ͬ�ġ�

����һ��ƽ���ַ���s�����㽫���ָ�ɾ����ܶ��ƽ���ַ�����

���ؿ���ͨ���ָ�õ���ƽ���ַ��������������



ʾ�� 1��

���룺s = "RLRRLLRLRL"
�����4
���ͣ�s ���Էָ�Ϊ "RL", "RRLL", "RL", "RL", ÿ�����ַ����ж�������ͬ������ 'L' �� 'R'��
ʾ�� 2��

���룺s = "RLLLLRRRLR"
�����3
���ͣ�s ���Էָ�Ϊ "RL", "LLLRRR", "LR", ÿ�����ַ����ж�������ͬ������ 'L' �� 'R'��
ʾ�� 3��

���룺s = "LLLLRRRR"
�����1
���ͣ�s ֻ�ܱ���ԭ�� "LLLLRRRR".


��ʾ��

1 <= s.length <= 1000
s[i] = 'L' �� 'R'

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/split-a-string-in-balanced-strings
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def balancedStringSplit(self, s: str) -> int:
        l = r = 0
        res = 0
        for i in range(len(s)):
            if s[i]=='R':
                r = r + 1
            elif s[i]=='L':
                l = l + 1
            if l==r:
                l = r = 0
                res = res + 1
        return res