class Solution {
public:
    int rob(vector<int>& nums) {
        //动态规划
        //0:不偷
        //1:偷
        /*if(nums.size()==0)
            return 0;
        vector<vector<int>> dp(nums.size(),vector<int>());
        for(int i=0;i<nums.size();i++)
        {
            dp[i].resize(2);
        }
        dp[0][0]=0;
        dp[0][1]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
            dp[i][1]=dp[i-1][0]+nums[i];
        }
        return max(dp[nums.size()-1][0],dp[nums.size()-1][1]);*/
        int tmp=0,cur=0,prev=0;
        for(int i=0;i<nums.size();i++)
        {
            tmp=cur;
            cur=max(cur,prev+nums[i]);
            prev=tmp;
        }
        return cur;
    }
};