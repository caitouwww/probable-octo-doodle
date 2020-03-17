class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        if(len(nums2)!=0):
            j=0
            i=0
            while i<m+n:
                if nums2[j]<nums1[i]:
                    nums1.insert(i,nums2[j])
                    j=j+1
                    if j==len(nums2):
                        break
                i=i+1
            while j<len(nums2):
                nums1.insert(m+j,nums2[j])
                j=j+1
            nums1[:]=nums1[0:m+n]