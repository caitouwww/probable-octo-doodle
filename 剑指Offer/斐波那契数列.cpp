class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0)    return 0;
        else if(n == 1)    return 1;
        int first = 0, second = 1;
        for(int i = 2; i < n + 1; i++){
            int tmp = second;
            second = second + first;
            first = tmp;
        }
        return second;
    }
};