class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        if len(nums)==0:
            return 0
        p=0
        q=0
        while q<len(nums):
            if nums[q]==val:
                q=q+1
            else:
                nums[p]=nums[q]
                q=q+1
                p=p+1
        return p