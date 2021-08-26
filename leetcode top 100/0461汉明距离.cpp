class Solution {
public:
    int hammingDistance(int x, int y) {
        x = x^y;
        int cnt = 0;
        while(x){
            cnt++;
            x&=(x-1);
        }
        return cnt;
    }
};
