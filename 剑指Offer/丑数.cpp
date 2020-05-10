class Solution {
public:
    int GetUglyNumber_Solution(int n) {
        if(!n)    return 0;
        vector<int> u(n, 0);
        u[0] = 1;
        int i = 0, j = 0, k = 0;
        for(int index = 1; index < n; index++){
            int tmp = min(min(u[i] * 2, u[j] * 3), u[k] * 5);
            if(tmp == u[i] * 2)    i++;
            if(tmp == u[j] * 3)    j++;
            if(tmp == u[k] * 5)    k++;
            u[index] = tmp;
        }
        return u[n - 1];
    }
};
