# -*- coding:utf-8 -*-
class Solution:
    def StrToInt(self, s):
        # write code here
        if not s:
            return 0
        flag = 1
        if s[0] == '-':
            flag = -1
            s = s[1:]
        elif s[0] == '+':
            s = s[1:]
        s = s[::-1]
        cnt = 1
        ans = 0
        for c in s:
            if c.isdigit():
                ans += (ord(c) - 48) * cnt
                cnt *= 10
            else:
                ans = 0
                break
        return ans * flag