"""
��������û���ظ�Ԫ�ص�����nums1 ��nums2������nums1��nums2���Ӽ����ҵ�nums1��ÿ��Ԫ����nums2�е���һ��������ֵ��

nums1������x����һ������Ԫ����ָx��nums2�ж�Ӧλ�õ��ұߵĵ�һ����x���Ԫ�ء���������ڣ���Ӧλ�����-1��

ʾ�� 1:

����: nums1 = [4,1,2], nums2 = [1,3,4,2].
���: [-1,3,-1]
����:
    ����num1�е�����4�����޷��ڵڶ����������ҵ���һ����������֣������� -1��
    ����num1�е�����1���ڶ�������������1�ұߵ���һ���ϴ������� 3��
    ����num1�е�����2���ڶ���������û����һ����������֣������� -1��
ʾ�� 2:

����: nums1 = [2,4], nums2 = [1,2,3,4].
���: [3,-1]
����:
    ����num1�е�����2���ڶ��������е���һ���ϴ�������3��
    ����num1�е�����4���ڶ���������û����һ����������֣������� -1��
ע��:

nums1��nums2������Ԫ����Ψһ�ġ�
nums1��nums2�������С��������1000��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/next-greater-element-i
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        """
        l1 = len(nums1)
        l2 = len(nums2)
        res = [0]*l1
        for i in range(l1):
            j = nums2.index(nums1[i]) + 1
            #start = j
            while j<l2:
                if nums2[j]<=nums1[i]:
                    j = j + 1
                else:
                    res[i] = nums2[j]
                    break
            if j==l2:
                res[i] = -1
        return res
        """
        """
        stack = []
        hash = {}
        if len(nums1)==0:
            return []
        elif len(nums1)==1:
            return [-1]
        else:
            stack.append(nums2[0])
            for i in range(1,len(nums2)):
                if nums2[i]<=stack[-1]:
                    stack.append(nums2[i])
                else:
                    while stack[-1]<nums2[i]:
                        hash[stack[-1]] = nums2[i]
                        stack.pop()
                        if len(stack)==0:
                            break
                    stack.append(nums2[i])
            while len(stack)!=0:
                hash[stack[-1]]=-1
                stack.pop()
            res = []
            for i in nums1:
                res.append(hash[i])
            return res
            """
        #����ջ
        hasha = {}
        stack = []
        for i in range(len(nums2)-1,-1,-1):
            while len(stack)!=0 and stack[-1]<=nums2[i]:
                stack.pop()
            if len(stack)==0:
                hasha[nums2[i]]=-1
            else:
                hasha[nums2[i]]=stack[-1]
            stack.append(nums2[i])

        res = []
        for i in nums1:
            res.append(hasha[i])
        return res