class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int res = 0;
        for(auto x : data){
            res ^= x;
        }
        int idx = 0;
        while((res & 1) == 0){
            idx++;
            res >>= 1;
        }
        int n1 = 0, n2 = 0;
        for(auto x : data){
            if(((x >> idx) & 1) == 0)    n1 ^= x;
            else    n2 ^= x;
        }
        *num1 = n1;
        *num2 = n2;
    }
};