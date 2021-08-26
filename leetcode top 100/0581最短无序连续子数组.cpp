class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // if(nums.empty())return 0;
        // int n = nums.size();
        // vector<int> maxm(n,nums[0]), minm(n,nums[n-1]);
        // for(int i = 1; i < n; ++i){
        //     maxm[i] = max(maxm[i-1],nums[i]);
        // }
        // for(int i = n-2; i >=0; --i){
        //     minm[i] = min(minm[i+1],nums[i]);
        // }
        // int l, r;
        // for(int i = 0; i < n; ++i){
        //     if(nums[i]>minm[i]){
        //         l = i;
        //         break;
        //     }
        // }
        // for(int i = n-1; i >= 0; --i){
        //     if(nums[i]<maxm[i]){
        //         r = i;
        //         break;
        //     }
        // }
        // if(l>r)return 0;
        // else return r-l+1;

        // if(nums.size()<2)return 0;
        // int maxm = INT_MIN;
        // int minm = INT_MAX;
        // int r = 0, l = 0;
        // for(int i = 0; i < nums.size(); ++i){
        //     if(maxm>nums[i]){
        //         r = i;
        //     }
        //     maxm = max(maxm,nums[i]);
        // }
        // for(int i = nums.size()-1; i >= 0; --i){
        //     if(minm < nums[i]){
        //         l = i;
        //     }
        //     minm = min(minm,nums[i]);
        // }
        // return l==r?0:r-l+1;

        if(nums.size()<2)return 0;
        int maxm = INT_MIN, minm = INT_MAX;
        int len = nums.size();
        int l = 0, r = 0;
        for(int i = 0; i < len; ++i){
            maxm = max(maxm,nums[i]);
            minm = min(minm,nums[len-1-i]);
            if(maxm>nums[i])r = i;
            if(minm<nums[len-1-i])l = len-1-i;
        }
        return r>l?r-l+1:0;
    }
};
