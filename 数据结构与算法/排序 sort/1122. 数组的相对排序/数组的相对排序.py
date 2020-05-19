"""
给你两个数组，arr1和arr2，

arr2中的元素各不相同
arr2中的每个元素都出现在arr1中
对 arr1中的元素进行排序，使arr1中项的相对顺序和arr2中的相对顺序相同。未在arr2中出现过的元素需要按照升序放在arr1的末尾。



示例：

输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
输出：[2,2,2,1,4,3,3,9,6,7,19]


提示：

arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
arr2中的元素arr2[i]各不相同
arr2中的每个元素arr2[i]都出现在arr1中

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/relative-sort-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        """
        dic = {}
        res2 = []
        for i in arr2:
            dic[i] = 0
        for i in arr1:
            if i in dic.keys():
                dic[i] = dic[i] + 1
            else:
                res2.append(i)
        res2.sort()
        res = [i  for i in dic.keys() for j in range(dic[i])]
        res = res + res2
        return res
        """
        arr2 += sorted(set(arr1)-set(arr2))
        arr1.sort(key=arr2.index)
        return arr1