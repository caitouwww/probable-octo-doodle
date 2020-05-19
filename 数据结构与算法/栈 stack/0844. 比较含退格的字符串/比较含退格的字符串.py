"""
���� S �� T �����ַ����������Ƿֱ����뵽�հ׵��ı��༭�����ж϶����Ƿ���ȣ������ؽ���� # �����˸��ַ���



ʾ�� 1��

���룺S = "ab#c", T = "ad#c"
�����true
���ͣ�S �� T ������ ��ac����
ʾ�� 2��

���룺S = "ab##", T = "c#d#"
�����true
���ͣ�S �� T ������ ������
ʾ�� 3��

���룺S = "a##c", T = "#a#c"
�����true
���ͣ�S �� T ������ ��c����
ʾ�� 4��

���룺S = "a#c", T = "b"
�����false
���ͣ�S ���� ��c������ T ��Ȼ�� ��b����


��ʾ��

1 <= S.length <= 200
1 <= T.length <= 200
S �� T ֻ����Сд��ĸ�Լ��ַ� '#'��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/backspace-string-compare
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        stacks = []
        stackt = []
        for ch in S:
            if ch=="#":
                if len(stacks)!=0:
                    stacks.pop()
            else:
                stacks.append(ch)
        for ch in T:
            if ch=="#":
                if len(stackt)!=0:
                    stackt.pop()
            else:
                stackt.append(ch)

        return stacks==stackt
