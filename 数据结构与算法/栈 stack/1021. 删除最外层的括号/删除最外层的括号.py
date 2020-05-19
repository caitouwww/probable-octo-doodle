"""
有效括号字符串为空("")、"(" + A + ")"或A + B，其中A和B都是有效的括号字符串，+代表字符串的连接。例如，""，"()"，"(())()"和"(()(()))"都是有效的括号字符串。

如果有效字符串S非空，且不存在将其拆分为S = A+B的方法，我们称其为原语（primitive），其中A和B都是非空有效括号字符串。

给出一个非空有效字符串S，考虑将其进行原语化分解，使得：S = P_1 + P_2 + ... + P_k，其中P_i是有效括号字符串原语。

对S进行原语化分解，删除分解中每个原语字符串的最外层括号，返回 S。



示例 1：

输入："(()())(())"
输出："()()()"
解释：
输入字符串为 "(()())(())"，原语化分解得到 "(()())" + "(())"，
删除每个部分中的最外层括号后得到 "()()" + "()" = "()()()"。
示例 2：

输入："(()())(())(()(()))"
输出："()()()()(())"
解释：
输入字符串为 "(()())(())(()(()))"，原语化分解得到 "(()())" + "(())" + "(()(()))"，
删除每隔部分中的最外层括号后得到 "()()" + "()" + "()(())" = "()()()()(())"。
示例 3：

输入："()()"
输出：""
解释：
输入字符串为 "()()"，原语化分解得到 "()" + "()"，
删除每个部分中的最外层括号后得到 "" + "" = ""。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-outermost-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        """
        left = 0
        right = 0
        stack = []
        l = len(S)
        _ = 0
        str = ''
        while right < l-1:
        #for _ in range(len(S)):
            if S[_] is '(':
                stack.append(S[_])
            elif S[_] is ')':
                stack.pop()
            if len(stack)==0:
                right = _
                str = str + S[left+1:right]
                #S = S[left+1:right]+S[right+1:]
                left = right + 1
                right = left + 1
            _ = _ + 1
        S = str
        return S
        """
        l = 1
        r = 0
        res = ''
        length = len(S)
        i = 1
        while i<length:
        #for i in range(len(S)):
            if S[i]=='(':
                l = l + 1
            else:
                r = r + 1
            if l!=r:
                res = res + S[i]
            else:
                l = 1
                r = 0
                i = i + 1
            i = i + 1
        return res