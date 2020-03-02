"""
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

示例1:
s = "abc", t = "ahbgdc"

返回true.

示例2:
s = "axc", t = "ahbgdc"

返回false.

后续挑战 :

如果有大量输入的 S，称作S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/is-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        """
        for i in s:
            if i in t:
                t = t[t.index(i)+1:]
            else:
                return False
        return True
        """
        point_s = 0
        point_t = 0
        len_s = len(s)
        len_t = len(t)
        while point_s < len_s and point_t < len_t:
            if s[point_s]==t[point_t]:
                point_s = point_s + 1
            point_t = point_t + 1
        return point_s == len_s