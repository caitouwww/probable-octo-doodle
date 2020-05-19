class Solution {
public:
    int mySqrt(int x) {
        //二分法
        /*int left =0;
        int right = x/2+1;
        while(left<right)
        {
            int mid = left+(right-left+1)/2;
            if(mid>x/mid)
                right=mid-1;
            else
                left=mid;
        }
        return left;*/
        //牛顿迭代法
        if(x==0)
            return 0;
        else
        {
            long num = x;
            while(num>x/num)
            {
                num=(num+x/num)/2;
            }
            return num;           
        }
    }
};