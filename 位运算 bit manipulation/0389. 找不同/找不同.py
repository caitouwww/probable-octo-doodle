"""
给定两个字符串 s 和 t，它们只包含小写字母。

字符串t由字符串s随机重排，然后在随机位置添加一个字母。

请找出在 t 中被添加的字母。



示例:

输入：
s = "abcd"
t = "abcde"

输出：
e

解释：
'e' 是那个被添加的字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-difference
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        """
        ls = list(s)
        lt = list(t)

        for i in ls:
            lt.remove(i)
        return lt[0]
        """
        #ord将单个字符转为ascii码值，chr将单个ascii码值转为字符
        #map(ord,t)转换字符串
        return chr(sum(map(ord,t))-sum(map(ord,s)))