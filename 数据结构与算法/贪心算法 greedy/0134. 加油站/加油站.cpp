class Solution {
public:
    //暴力
    // int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //     int size = gas.size();
    //     if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) return -1;
    //     for(int i = 0; i < size; i++){
    //         int remain = 0;
    //         for(int j = i; j< size; j++){
    //             j = j % size;
    //             remain += gas[j];
    //             remain -= cost[j];
    //             if(remain < 0)  break;
    //         }
    //         if(remain >= 0) return i;
    //     }
    //     return -1;
    // }
    // 1 不用很复杂，一次遍历做好两件事：

    // 2 rest代表总的油数和消耗数目之差

    // 3 oil_minvalue 表示遍历过程中，rest能到达的最小值

    // 4 record_point 代表每一次的rest取更小的值时，当前的加油站的位置。

    // 5 rest<0 代表失败，结果就是-1

    // 6 在当前最小的rest，即oil_minvalue处，记录当前加油站的位置，只用从下个位置出发，并且保证最终的rest>=0，那么下个位置就是答案。即record_point + 1
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        int rest = 0;
        int oil_minvalue = 0;
        int record_point = -1;
        for(int i = 0; i < gas.size(); i++){
            rest += gas[i] - cost[i];
            if(rest < oil_minvalue){
                oil_minvalue = rest;
                record_point = i;
            }
        }
        if(rest < 0)    return -1;
        else    return record_point + 1;
    }
};