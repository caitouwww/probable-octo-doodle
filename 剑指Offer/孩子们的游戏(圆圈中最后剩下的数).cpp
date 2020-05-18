class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        int ans = 0;
        for(int i = 2; i <= n; i++){
            ans = (ans + m) % i;
        }
        if(n >= 2)    return ans;
        else    return -1;
    }
};