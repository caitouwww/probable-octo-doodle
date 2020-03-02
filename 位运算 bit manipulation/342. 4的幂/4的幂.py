"""
给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4?的幂次方。

示例 1:

输入: 16
输出: true
示例 2:

输入: 5
输出: false
进阶：
你能不使用循环或者递归来完成本题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/power-of-four
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        """
        if num==0:
            return False
        while num%4==0:
            num = num // 4
        if num==1:
            return True
        else:
            return False
        """
        """
        if num==0:
            return False
        elif num==1:
            return True
        elif num%4==0:
            return self.isPowerOfFour(num//4)
        else:
            return False
        """
        """
        return bin(num).count('1')==1 and num&0x55555555==num
        """
        if num<0 or num&(num-1):
            return False
        return num&0x55555555