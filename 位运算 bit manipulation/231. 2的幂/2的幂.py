"""
给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

示例1:

输入: 1
输出: true
解释: 20= 1
示例 2:

输入: 16
输出: true
解释: 24= 16
示例 3:

输入: 218
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/power-of-two
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        """
        if n <= 0:
            return False 
        elif n == 1:
            return True
        else:
            while n>=2:
                if n %2 != 0:
                    return False
                else:
                    n = n // 2
        return True
        """
        return n>0 and not n&n-1