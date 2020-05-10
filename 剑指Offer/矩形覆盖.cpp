class Solution {
public:
    int rectCover(int n) {
        if(n == 0)    return 0;
        if(n == 1)    return 1;
        if(n == 2)    return 2;
        return rectCover(n - 1) + rectCover(n - 2);
    }
};
