class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1)return false;
        int target = sum/2;
        vector<bool> dp(target+1,false);
        dp[0] = true;
        for(auto&n:nums){
            for(int j = target; j >= n; --j){
                if(dp[target])return true;
                dp[j] = dp[j] || dp[j-n];
            }
        }
        return dp[target];
    }
};
