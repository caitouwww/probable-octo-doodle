class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int cnt = 0;
        long i = 1;
        while(n / i != 0){
            long high = n / (i * 10);
            long cur = (n / i) % 10;
            long low = n - (n / i) * i;
            if(cur == 0)    cnt += high * i;
            else if(cur == 1)    cnt += high * i + low + 1;
            else    cnt += high * i + i;
            i = i * 10;
        }
        return cnt;
    }
};