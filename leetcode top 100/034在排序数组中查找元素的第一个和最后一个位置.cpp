class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())return {-1,-1};
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<r){
            int m = l + ((r-l)>>1);
            if(nums[m]>=target)r=m;
            else l = m+1;
        }
        //利用二分思想先找其左边界，再找其右边界即可，注意找左边界的时候，由右侧逼近；找右边界的时候，由左侧逼近，即可。
        if(nums[l]!=target)return{-1,-1};
        int first = l;
        l = 0, r = n;
        while(l<r){
            int m = l + ((r-l)>>1);
            if(nums[m]<=target)l = m+1;
            else r=m;
        }
        return {first,l-1};
    }
};
