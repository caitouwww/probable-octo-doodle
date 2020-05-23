class Solution {
public:
    //����
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
    // 1 ���úܸ��ӣ�һ�α������������£�

    // 2 rest�����ܵ�������������Ŀ֮��

    // 3 oil_minvalue ��ʾ���������У�rest�ܵ������Сֵ

    // 4 record_point ����ÿһ�ε�restȡ��С��ֵʱ����ǰ�ļ���վ��λ�á�

    // 5 rest<0 ����ʧ�ܣ��������-1

    // 6 �ڵ�ǰ��С��rest����oil_minvalue������¼��ǰ����վ��λ�ã�ֻ�ô��¸�λ�ó��������ұ�֤���յ�rest>=0����ô�¸�λ�þ��Ǵ𰸡���record_point + 1
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