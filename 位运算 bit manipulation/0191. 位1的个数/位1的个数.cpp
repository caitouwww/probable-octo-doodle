class Solution {
public:
    int hammingWeight(uint32_t n) {
        /*bitset<32> b=n;
        return b.count();*/
        /*int count=0;
        while(n)
        {
            if(n&1==1)
                count++;
            n>>=1;
        }
        return count;*/
        /*int count=0;
        while(n!=0)
        {
            count++;
            n&=(n-1);//总是把n中的最后面的一个1消掉
        }
        return count;*/
        //分治算法
        n = (n & (0x55555555)) + ((n >> 1) & (0x55555555));
        n = (n & (0x33333333)) + ((n >> 2) & (0x33333333));
        n = (n & (0x0F0F0F0F)) + ((n >> 4) & (0x0F0F0F0F));
        n = (n & (0x00FF00FF)) + ((n >> 8) & (0x00FF00FF));
        n = (n & (0x0000FFFF)) + ((n >> 16) & (0x0000FFFF));
        return n;
    }
};