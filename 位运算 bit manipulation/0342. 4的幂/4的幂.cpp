class Solution {
public:
    bool isPowerOfFour(int num) {
        /*if(num<=0)
            return false;
        while(num%4==0)
        {
            num/=4;
        }
        if(num==1)
            return true;
        else
            return false;*/
        /*if(num<=0)
            return false;
        bitset<32> b=num;
        if((b.count()==1)&&((num&0x55555555)==num))
            return true;
        else
            return false;*/
        //暴力法-预计算
        /*vector<int> save(16,1);
        for(int i=1;i<16;i++)
        {
            save[i]=4*save[i-1];
        }
        for(int val:save)
        {
            if(val==num)
                return true;
        }
        return false;*/
        //数学运算
        /*if((num>0)&&(abs(int(log(num)/log(2))-log(num)/log(2))==0))
            return (int(log(num)/log(2)))%2==0;
        else
            return false;*/
        //位操作
        //return (num>0)&&((num&num-1)==0)&&((num&0xaaaaaaaa)==0);//优先级(?):==、&、&&
        //位运算+数学运算
        return (num>0)&&((num&num-1)==0)&&(num%3==1);
    }
};