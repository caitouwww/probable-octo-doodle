class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> dp(n,1);
        // for(int i = 0; i < n; ++i){
        //     for(int j = 0; j < i; ++j){
        //         if(nums[i]>nums[j]){
        //             dp[i] = max(dp[i],dp[j]+1);
        //         }
        //     }
        // }
        // int res = 0;
        // for(int i = 0; i < n; ++i){
        //     res = max(res,dp[i]);
        // }
        // return res;
        int n = nums.size();
        vector<int> incre;
        incre.push_back(nums[0]);
        int len = 1;
        for(int i = 1; i < n; ++i){
            if(nums[i]>incre[len-1]){
                incre.push_back(nums[i]);
                len++;
            }else{
                auto iter = lower_bound(incre.begin(),incre.end(),nums[i]);
                *iter = nums[i];
                // int l = 0, r = len - 1;
                // while(l < r){
                //     int m = l + (r-l)/2;
                //     if(incre[m]<nums[i])l = m + 1;
                //     else r = m;
                // }
                // incre[l] = nums[i];
            }
        }
        return len;
    }
};
