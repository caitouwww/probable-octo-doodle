"""
���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ����ĸ��λ�ʡ�

ʾ��?1:

����: s = "anagram", t = "nagaram"
���: true
ʾ�� 2:

����: s = "rat", t = "car"
���: false
˵��:
����Լ����ַ���ֻ����Сд��ĸ��

����:
��������ַ������� unicode �ַ���ô�죿���ܷ������Ľⷨ��Ӧ�����������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/valid-anagram
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        """
        ls = len(s)
        lt = len(t)
        if ls!=lt:
            return False
        else:
            if ls==0:
                return True
            sdci = {}
            tdic = {}
            for i in range(ls):
                if s[i] in sdci.keys():
                    sdci[s[i]] = sdci[s[i]] + 1
                else:
                    sdci[s[i]] = 1
                if t[i] in tdic.keys():
                    tdic[t[i]] = tdic[t[i]] + 1
                else:
                    tdic[t[i]] = 1
            if sdci == tdic:
                return True
            else:
                return False
        """
        return sorted(s)==sorted(t)