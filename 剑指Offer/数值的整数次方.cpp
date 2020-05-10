class Solution {
public:
    double Power(double base, int exponent) {
        if(base == 0)    return 0.0;
        if(exponent == 0)    return 1.0;
        double res = 1.0;
        if(exponent < 0){
            base = 1.0 / base;
            exponent = -exponent;
        }
        for(int i = 0; i < exponent; i++){
            res *= base;
        }
        return res;
    }
};