class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle)==0:
            return 0
        i=0
        j=0
        lenh=len(haystack)
        lenn=len(needle)
        while i<lenh and j<lenn:
            if haystack[i]==needle[j]:
                i=i+1
                j=j+1
            else:
                i=i-j+1
                j=0
        if j==lenn:
            return i-j
        return -1