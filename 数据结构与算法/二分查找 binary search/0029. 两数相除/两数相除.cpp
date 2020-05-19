class Solution {
public:
    //超时
    /*int dulpicate(int dividend,int divisor)
    {
        int res=0;
        int sign=0;
        if((dividend>0&&divisor>0)||(dividend<0&&divisor<0)) sign=1;
        dividend=abs(dividend);
        divisor=abs(divisor);
        while(dividend>=divisor)
        {
            dividend-=divisor;
            res++;
        }
        if(sign==1) return res;
        else    return -res;
    }
    int divide(int dividend, int divisor) {
        
        if(dividend==0) return 0;
        if(dividend==INT32_MIN)
        {
            if(divisor==1) return dividend;
            else if(divisor==-1)    return  INT32_MAX;
            else
            {
                return dulpicate(dividend+1,divisor);
            }
        }
        return dulpicate(dividend,divisor);
    }*/
    //用long类型
    /*int div(long a,long b)
    {
        if(a<b) return 0;
        long count=1;
        long tb=b;
        while((tb+tb)<=a)
        {
            count=count+count;
            tb=tb+tb;
        }
        return count+div(a-tb,b);
    }
    int divide(int dividend, int divisor)
    {
        if(dividend==0) return 0;
        if(divisor==1)  return dividend;
        if(divisor==-1){
            if(dividend>INT32_MIN)  return -dividend;
            return INT32_MAX;
        }
        long a=dividend;
        long b=divisor;
        int sign=1;
        if((a>0&&b<0)||(a<0&&b>0))  sign=-1;
        a=a>0?a:-a;
        b=b>0?b:-b;
        long res=div(a,b);
        if(sign>0)  return res;
        else    return -res;
    }*/
    int divide_aux(int dividend, int divisor)
    {
        if(dividend<=0&&divisor<=0)
        {
            if(dividend>divisor)    return 0;
        }
        else
        {
            if(dividend<divisor)    return 0;
        }
        if(dividend==divisor)   return 1;
        int db=divisor;
        int cnt=1;
        while(1)
        {
            if(dividend<=0&&divisor<=0)
            {
                if(dividend-db>db)  break;
            }
            else
            {
                if(dividend-db<db)  break;
            }
            cnt=cnt+cnt;
            db=db+db;
        }
        return cnt+divide_aux(dividend-db,divisor);
    }
    //不用long类型
    int divide(int dividend, int divisor)
    {
        if(dividend==0) return 0;
        if(divisor==1)  return dividend;
        if(divisor==-1)
        {
            if(dividend>INT32_MIN)  return -dividend;
            return INT32_MAX;
        }
        bool isSign=(dividend>>31)^(divisor>>31);
        //若一正一负，同时变成负数来处理，避免溢出
        if(isSign)
        {
            divisor=divisor<0?divisor:-divisor;
            dividend=dividend<0?dividend:-dividend;
        }
        int res=divide_aux(dividend,divisor);
        res=isSign?-res:res;
        return res;
    }
};