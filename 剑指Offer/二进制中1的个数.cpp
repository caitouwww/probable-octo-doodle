class Solution {
public:
     int  NumberOf1(int n) {
         /*int res = 0;
         while(n != 0){
             res++;
             n &= (n - 1);
             //若采用if(n&1) res++;n>>=1;会导致负数的情况下会因为右移时左边补1造成死循环
         }
         //将一个运算对象的各二进制位全部左移若干位（左边的二进制丢弃，右边补0）
         //将一个运算对象的各二进制位全部右移若干位，正数左补0，负数左补1.
         return res;*/
         bitset<32> b = n;
         return b.count();
     }
};