class Solution {
public:
// 如果所有元素都不为0， 那么一定可以跳到最后；
// 从后往前遍历，如果遇到nums[i] = 0，就找i前面的元素j，使得nums[j] > i - j。如果找不到，则不可能跳跃到num[i+1]，返回false。
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
    //贪心算法，每个位置都计算自己能达到的最远距离，同时每个位置要判断自己是否可达，也就是本位置需要在当前最远能到达的距离中。最终计算出来能到达的最远距离，与数组长度比较即可。
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