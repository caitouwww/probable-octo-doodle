"""
给定一个非负整数数组A， A 中一半整数是奇数，一半整数是偶数。

对数组进行排序，以便当A[i] 为奇数时，i也是奇数；当A[i]为偶数时， i 也是偶数。

你可以返回任何满足上述条件的数组作为答案。



示例：

输入：[4,2,5,7]
输出：[4,5,2,7]
解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。


提示：

2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-array-by-parity-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        """
        j = 0
        k = 1
        #A.sort()
        l = len(A)
        res = [0]*l
        for i in range(l):
            if A[i]%2==0:
                res[j] = A[i]
                j = j + 2
            else:
                res[k] = A[i]
                k = k + 2
        return res
        """
        """
        even = [i for i in A if not i%2]
        odd = [i for i in A if i%2]
        return [i for n in zip(even,odd) for i in n]
        """
        """
        from itertools import chain
        odd = []
        even = []
        for i in A:
            if i&1:
                odd.append(i)
            else:
                even.append(i)
        return list(chain(*zip(even,odd)))
        """
        """
        res = [None]*len(A)
        res[::2]=(x for x in A if x%2==0)
        res[1::2]=(x for x in A if x%2==1)
        return res
        """
        j = 1
        for i in range(0,len(A),2):
            if A[i]%2==1:
                while A[j]%2==1:
                    j = j + 2
                A[i],A[j] = A[j],A[i]
        return A