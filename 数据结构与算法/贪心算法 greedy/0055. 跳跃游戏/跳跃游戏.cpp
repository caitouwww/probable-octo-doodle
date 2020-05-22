class Solution {
public:
// �������Ԫ�ض���Ϊ0�� ��ôһ�������������
// �Ӻ���ǰ�������������nums[i] = 0������iǰ���Ԫ��j��ʹ��nums[j] > i - j������Ҳ������򲻿�����Ծ��num[i+1]������false��
    // bool canJump(vector<int>& nums) {
    //     int size = nums.size();
    //     for(int i = size - 2; i != -1; i--){
    //         if(!nums[i]){
    //             int j = 0;
    //             for(j = i - 1; j != -1; j--){
    //                 if(nums[j] > i - j) break;
    //             }
    //             if(j == -1) return false;
    //         }
    //     }
    //     return true;
    // }
    //̰���㷨��ÿ��λ�ö������Լ��ܴﵽ����Զ���룬ͬʱÿ��λ��Ҫ�ж��Լ��Ƿ�ɴҲ���Ǳ�λ����Ҫ�ڵ�ǰ��Զ�ܵ���ľ����С����ռ�������ܵ������Զ���룬�����鳤�ȱȽϼ��ɡ�
    bool canJump(vector<int>& nums){
        int size = nums.size();
        if(size <= 1)   return true;
        int maxDis = nums[0];
        for(int i = 1; i < size - 1; i++){
            if(i <= maxDis) maxDis = max(maxDis, nums[i] + i);
        }
        return maxDis >= size - 1;
    }
};