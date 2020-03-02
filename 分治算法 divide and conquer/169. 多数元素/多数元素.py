"""
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于?? n/2 ??的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例?1:

输入: [3,2,3]
输出: 3
示例?2:

输入: [2,2,1,1,1,2,2]
输出: 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        #n = len(nums)
        #mid = n//2
        """
        dic = {}
        for i in nums:
            if i in dic.keys():
                dic[i]=dic[i]+1
            else:
                dic[i]=1
        for i,j in dic.items():
            if j==max(dic.values()):
                return i
        """
        cnt, res = 1, nums[0]
        for i in range(1,len(nums)):
            if res==nums[i]:
                cnt = cnt + 1
            else:
                cnt = cnt - 1
                if cnt == 0:
                    res = nums[i+1]
        return res