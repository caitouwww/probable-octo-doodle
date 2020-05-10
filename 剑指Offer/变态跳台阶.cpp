class Solution {
public:
    int jumpFloorII(int number) {
        /*if(number == 0)    return 1;
        if(number == 1)    return 1;
        if(number == 2)    return 2;
        int res = 0;
        for(int i = 1; i < number + 1; i++){
            res += jumpFloorII(number - i);
        }
        return res;*/
        vector<int> res(number + 1, 0);
        res[0] = 1;
        res[1] = 1;
        res[2] = 2;
        for(int i = 3; i < number + 1; i++){
            int j = i;
            while(j--){
                res[i] += res[j];
            }
        }
        return res[number];
    }
};