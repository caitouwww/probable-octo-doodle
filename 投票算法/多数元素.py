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