"""
不使用运算符+ 和-，计算两整数a、b之和。

示例 1:

输入: a = 1, b = 2
输出: 3
示例 2:

输入: a = -2, b = 3
输出: 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-two-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
class Solution:
    def getSum(self, a: int, b: int) -> int:
        MASK = 0x100000000
        MAX_INT = 0x7fffffff
        MIN_INT = MAX_INT + 1
        while b!=0:
            carry = (a & b) << 1
            a = (a ^ b) % MASK
            b = carry % MASK
        return a if a <=MAX_INT else ~((a % MIN_INT) ^ MAX_INT)
		
		
class Solution:
    def getSum(self, a: int, b: int) -> int:
        a&=0xffffffff
        b&=0xffffffff
        while b:
            carry = a & b
            a ^= b
            b= (carry<<1) & 0xffffffff
        return a if a < 0x80000000 else ~(a^0xffffffff)
