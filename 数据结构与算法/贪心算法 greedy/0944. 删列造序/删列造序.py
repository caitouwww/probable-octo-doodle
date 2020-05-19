"""
给定由N个小写字母字符串组成的数组 A，其中每个字符串长度相等。

删除 操作的定义是：选出一组要删掉的列，删去A中对应列中的所有字符，形式上，第 n列为[A[0][n], A[1][n], ..., A[A.length-1][n]]）。

比如，有A = ["abcdef", "uvwxyz"]，



要删掉的列为{0, 2, 3}，删除后 A为["bef", "vyz"]， A的列分别为["b","v"], ["e","y"], ["f","z"]。



你需要选出一组要删掉的列D，对A 执行删除操作，使 A 中剩余的每一列都是 非降序排列的，然后请你返回D.length的最小可能值。



示例 1：

输入：["cba", "daf", "ghi"]
输出：1
解释：
当选择 D = {1}，删除后 A 的列为：["c","d","g"] 和 ["a","f","i"]，均为非降序排列。
若选择 D = {}，那么 A 的列 ["b","a","h"] 就不是非降序排列了。
示例 2：

输入：["a", "b"]
输出：0
解释：D = {}
示例 3：

输入：["zyx", "wvu", "tsr"]
输出：3
解释：D = {0, 1, 2}


提示：

1 <= A.length <= 100
1 <= A[i].length <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-columns-to-make-sorted
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        """
        res = 0
        for i in range(len(A[0])):
            for j in range(len(A)-1):
                if A[j][i]>A[j+1][i]:
                    res = res + 1
                    break

        return res
        """
        res = 0
        for col in zip(*A):
            if any(col[i] > col[i+1] for i in range(len(col)-1)):
                res = res + 1
        return res