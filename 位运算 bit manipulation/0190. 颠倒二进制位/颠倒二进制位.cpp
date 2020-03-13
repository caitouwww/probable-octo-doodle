class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        /*uint32_t res=0;
        for(int i=31;i>=0;i--)
        {
            res=res|(((n>>(31-i))&1)<<i);
        }
        return res;*/
        /*int i=32;
        uint32_t res=0;
        while(i--)
        {
            res<<=1;
            res+=(n&1);
            n>>=1;
        }
        return res;*/
        bitset<32> b=n;
        for(int i=0;i<16;i++)
        {
            if(b[i]!=b[31-i])
            {
                b[i]=!b[i];
                b[31-i]=!b[31-i];
            }
        }
        return b.to_ulong();//将bitset转换成unsigned long类型
    }
};