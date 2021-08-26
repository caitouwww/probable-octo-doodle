//超时
//class Solution {
//public:
//    int res = INT_MIN;
//    int maxCoins(vector<int>& nums) {
//        vector<bool> used(nums.size(), false);
//        backtrack(nums,used,0,0);
//        return res;
//    }
//    void backtrack(vector<int>& nums, vector<bool>& used, int cur, int cnt){
//        if(nums.size()==cnt){
//            res = max(res,cur);
//            return;
//        }
//        int n = nums.size();
//        for(int i = 0; i < n; ++i){
//            if(!used[i]){
//                used[i] = true;
//                int tmp = nums[i];
//                int j = i-1;
//                while(j>=0&&used[j]==true)j--;
//                if(j<0)tmp*=1;
//                else tmp*=nums[j];
//                j = i+1;
//                while(j<n&&used[j]==true)j++;
//                if(j==n)tmp*=1;
//                else tmp*=nums[j];
//                backtrack(nums,used,cur+tmp,cnt+1);
//                used[i] = false;
//            }
//        }
//    }
//};
//dp
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n+2,1);
        for(int i = 0; i < n; ++i){
            temp[i+1] = nums[i];
        }
        int res = INT_MIN;
        vector<vector<int>> dp(n+2,vector<int>(n+2));
        for(int len = 3; len <= n+2; len++){
            for(int i = 0; i <= n+2-len; ++i){
                int res = 0;
                for(int k = i+1; k < i+len-1; ++k){
                    int left = dp[i][k];
                    int right = dp[k][i+len-1];
                    res = max(res,left+right+temp[i]*temp[k]*temp[i+len-1]);
                }
                dp[i][i+len-1] = res;
            }
        }
        return dp[0][n+1];
    }
};
