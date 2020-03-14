class Solution {
public:
    int getSum(int a, int b) {
        while(b)
        {
            auto carry=(unsigned int)(a&b)<<1;
            //这里负数不支持左移 而牛客的oj支持 需要在移位前强转为unsigned int
            a=a^b;
            b=carry;
        }
        return a;
    }
};