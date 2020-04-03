class Solution {
public:
    //二分
    /*
    double search(double x, long n)
    {
        if(n==0)    return 1;
        long cnt=1;
        double val=x;
        while(cnt<=n-cnt)
        {
            val=val*val;
            cnt=cnt+cnt;
        }
        return val*search(x,n-cnt);
    }
    double myPow(double x, int n) {
        if(n==0)    return 1;
        if(n<0)
        {
            x=1.0/x;
            long nn=n;
            nn=-nn;
            return search(x,nn);
        }
        else
            return search(x,n);
    }*/
    //递归
    /*double fast_pow(double x, long n)
    {
        if(n==0)    return 1.0;
        double half=fast_pow(x,n/2);
        if(n%2==0)  return half*half;
        else return half*half*x;
    }
    double myPow(double x, int n)
    {
        long N=n;
        if(N<0)
        {
            N=-N;
            x=1.0/x;
        }
        return fast_pow(x,N);
    }*/
    //迭代，可以参考剑指offer，更优雅的写法
    double myPow(double x, int n)
    {
        long N=n;
        if(N<0)
        {
            x=1.0/x;
            N=-N;
        }
        double res=1;
        double cur=x;
        for(long i=N;i;i/=2)
        {
            if(i%2==1)
                res=res*cur;
            cur=cur*cur;
        }
        return res;
    }
};