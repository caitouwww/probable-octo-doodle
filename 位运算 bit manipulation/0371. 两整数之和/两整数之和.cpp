class Solution {
public:
    int getSum(int a, int b) {
        while(b)
        {
            auto carry=(unsigned int)(a&b)<<1;
            //���︺����֧������ ��ţ�͵�oj֧�� ��Ҫ����λǰǿתΪunsigned int
            a=a^b;
            b=carry;
        }
        return a;
    }
};