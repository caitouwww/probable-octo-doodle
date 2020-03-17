class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums)==0:
            return 0
        p=0
        q=1
        while q<len(nums):
            if(nums[q]==nums[p]):
                q=q+1
            else:
                if q-p>1:
                    nums[p+1]=nums[q]
                p=p+1
                q=q+1
        return p+1