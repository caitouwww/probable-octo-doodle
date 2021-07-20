class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN;
        int ans = INT_MIN;
        for(int i = 0; i < n; ++i){
            res = max(res,0)+nums[i];
            ans = max(ans,res);
        }
        return ans;
    }
};
