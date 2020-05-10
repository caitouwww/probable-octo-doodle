class Solution {
public:
    int jumpFloor(int number) {
        if(number == 0)    return 0;
        if(number == 1)    return 1;
        if(number == 2)    return 2;
        //return jumpFloor(number - 1) + jumpFloor(number - 2);
        int oneStep = 1, twoStep = 2;
        int cur = 3;
        for(int i = 3; i < number + 1; i++){
            cur = oneStep + twoStep;
            oneStep = twoStep;
            twoStep = cur;
        }
        return cur;
    }
};