class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        '''
        if target in nums:
            return nums.index(target)
        else:
            if target<nums[0]:
                return 0
            elif target >nums[-1]:
                return len(nums)
            else:
                for i in range(len(nums)-1):
                    if nums[i]<target and nums[i+1]>target:
                        return i+1
        '''
        #return len([arg for arg in nums if arg<target])
        return nums.index(target) if target in nums else sorted([*nums,target]).index(target)
