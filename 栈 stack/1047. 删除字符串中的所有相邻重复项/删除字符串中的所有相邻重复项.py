"""
������Сд��ĸ��ɵ��ַ���?S���ظ���ɾ��������ѡ��������������ͬ����ĸ����ɾ�����ǡ�

�� S �Ϸ���ִ���ظ���ɾ��������ֱ���޷�����ɾ����

����������ظ���ɾ�������󷵻����յ��ַ������𰸱�֤Ψһ��

?

ʾ����

���룺"abbaca"
�����"ca"
���ͣ�
���磬�� "abbaca" �У����ǿ���ɾ�� "bb" ��������ĸ��������ͬ�����Ǵ�ʱΨһ����ִ��ɾ���������ظ��֮�����ǵõ��ַ��� "aaca"��������ֻ�� "aa" ����ִ���ظ���ɾ�����������������ַ���Ϊ "ca"��
?

��ʾ��

1 <= S.length <= 20000
S ����СдӢ����ĸ��ɡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def removeDuplicates(self, S: str) -> str:
        top = 0
        res = ''
        for ch in S:
            if top==0 or res[top-1]!=ch:
                res = res + ch
                top = top + 1
            else:
                top = top - 1
                res = res[:-1]
        return res