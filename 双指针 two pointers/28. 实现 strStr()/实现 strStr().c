/*
ʵ��strStr()������

����һ��haystack �ַ�����һ�� needle �ַ������� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� (��0��ʼ)����������ڣ��򷵻� -1��

ʾ�� 1:

����: haystack = "hello", needle = "ll"
���: 2
ʾ�� 2:

����: haystack = "aaaaa", needle = "bba"
���: -1
˵��:

��needle�ǿ��ַ���ʱ������Ӧ������ʲôֵ�أ�����һ���������кܺõ����⡣

���ڱ�����ԣ���needle�ǿ��ַ���ʱ����Ӧ������ 0 ������C���Ե�strstr()�Լ� Java��indexOf()���������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/implement-strstr
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
int strStr(char* haystack, char* needle) {
    int sizea=strlen(haystack);
    int sizeb=strlen(needle);
    int i=0;
    int j=0;
    int k=0;
    if(sizea<sizeb) return -1;
    if(sizeb==0) return 0;
    else
    {
        for(i=0;i<sizea;i++)
        {
            k=0;
            if(*(haystack+i)==*needle)
            {
                for(j=0;j<sizeb;j++)
                {
                    if(*(haystack+i+j)==*(needle+j))
                    {
                        k++;
                        if(k==sizeb) return i;
                    }
                }
                if(k!=sizeb&&((i+sizeb)==sizea)) return -1;
                
            }
        }
         return -1;
    }
    
   
}