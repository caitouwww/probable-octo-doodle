/*
����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�

����Լ������������ظ�Ԫ�ء�

ʾ��1:

����: [1,3,5,6], 5
���: 2
ʾ��2:

����: [1,3,5,6], 2
���: 1
ʾ�� 3:

����: [1,3,5,6], 7
���: 4
ʾ�� 4:

����: [1,3,5,6], 0
���: 0

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/search-insert-position
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
int searchInsert(int* nums, int numsSize, int target) {
    int i=0; 
    if(*(nums+numsSize-1)<target) return numsSize;
    if(*nums>target) return 0;
    for(i=0;i<numsSize;i++)
    {
        if(*(nums+i)==target) return i;
        else if(*(nums+i)<target&&*(nums+i+1)>target) return i+1;
    }
    return 0;
}