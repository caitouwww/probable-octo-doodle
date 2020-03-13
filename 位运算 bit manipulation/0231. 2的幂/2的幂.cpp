class Solution {
public:
    bool isPowerOfTwo(int n) {
        /*if(n<=0)
            return false;
        bitset<32> b=n;
        if(b.count()==1)
            return true;
        else
            return false;*/
        /*if(n<=0)
            return false;
        while(n%2==0)
        {
            n=n/2;
        }
        if(n==1)
            return true;
        else
            return false;*/
        //如何获取二进制最右边的1：x&(-x)
        //如何将二进制最右边的1设置为0：x&(x-1)
        /*if(n<=0)
            return false;
        long x=n;
        return (x&(x-1))==0;*/
        if(n<=0)
            return false;
        int x=n;
        return (x&(-x))==x;//注意优先级，==高于&
    }
};