class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.size()==1&&abs(nums[0])!=abs(target))return 0;
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum<target)return 0;
        target = sum+target;
        if(target%2==1)return 0;
        target = target/2;
        vector<int> dp(target+1,0);
        dp[0] = 1;
        for(auto&n:nums){
            for(int i = target; i>=n; --i){
                dp[i] = dp[i]+dp[i-n];
            }
        }
        return dp[target];
    }
};
