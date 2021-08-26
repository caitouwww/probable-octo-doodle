class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mn = nums[0], mx = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int mxx = mx, mnn = mn;
            mx = max(nums[i], max(mnn*nums[i],mxx*nums[i]));
            mn = min(nums[i], min(mnn*nums[i],mxx*nums[i]));
            ans = max(ans,mx);
        }
        return ans;
    }
};
