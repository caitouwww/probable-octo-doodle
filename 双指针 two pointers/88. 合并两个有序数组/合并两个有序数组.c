/*
��������������������?nums1 �� nums2���� nums2 �ϲ���?nums1?�У�ʹ��?num1 ��Ϊһ���������顣

˵��:

��ʼ��?nums1 �� nums2 ��Ԫ�������ֱ�Ϊ?m �� n��
����Լ���?nums1?���㹻�Ŀռ䣨�ռ��С���ڻ����?m + n�������� nums2 �е�Ԫ�ء�
ʾ��:

����:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

���:?[1,2,2,3,5,6]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/merge-sorted-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
void merge(int* nums1, int m, int* nums2, int n) {

    int i=0;int j=0;int k=0;
    if(n==0) return;
    else if(m==0) 
    {
        for(i=0;i<n;i++)
            nums1[i]=nums2[i];
    }
    else
    {
        for(i=m-1;i>=0;i--)
    {
        nums1[i+n]=nums1[i];
        nums1[i]=0;
    }
    for(j=0;j<n;j++)
    {
        for(i=k;i<m;i++)
        {
                if(nums1[i+n]<=nums2[j])
               {
                    nums1[i+j]=nums1[i+n];
                    k++;
               }
        }
        nums1[k+j]=nums2[j];
    }
    }
}