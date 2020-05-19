class Solution {
public:
//     //加备忘录，自顶向下的动态规划解法
//     int rob(vector<int>& nums) {
//         vector<int> memo(nums.size(), -1);
//         return dp(nums, 0, memo);
//     }
// private:
//     int dp(vector<int>& nums, int start, vector<int>& memo){
//         if(start >= nums.size())    return 0;
//         if(memo[start] != -1)   return memo[start];
//         int res = max(dp(nums, start + 1, memo), nums[start] + dp(nums, start + 2, memo));
//         memo[start] = res;
//         return res;
//     }
    //自底向上
    // int rob(vector<int> & nums){
    //     int n = nums.size();
    //     vector<int> dp(n + 2);
    //     for(int i = n - 1; i >= 0; i--){
    //         dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
    //     }
    //     return dp[0];
    // }
    //优化
    int rob(vector<int>& nums){
        int n = nums.size();
        int dp_i_1 = 0, dp_i_2 = 0;
        int dp_i = 0;
        for(int i = n - 1; i >= 0; i--){
            dp_i = max(dp_i_1, nums[i] + dp_i_2);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }
};
