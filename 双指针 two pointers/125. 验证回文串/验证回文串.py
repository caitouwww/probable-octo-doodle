"""
����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��

˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���

ʾ�� 1:

����: "A man, a plan, a canal: Panama"
���: true
ʾ�� 2:

����: "race a car"
���: false

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/valid-palindrome
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def isPalindrome(self, s: str) -> bool:
        """
        s1 = "".join(s.split())
        tmpS = []
        for i in s1:
            if i.isdigit() or i.isalpha():
                i = i.upper()
                tmpS.append(i)
        l = len(tmpS)
        for i in range(l):
            if tmpS[i]!=tmpS[l-1-i]:
                return False
        return True
        """
        left, right = 0, len(s) - 1
        while left < right:
            while left < right and not s[left].isalnum():
                left += 1
            while left < right and not s[right].isalnum():
                right -= 1
            if s[left].lower() != s[right].lower():
                return False
            left += 1
            right -= 1
        return True
