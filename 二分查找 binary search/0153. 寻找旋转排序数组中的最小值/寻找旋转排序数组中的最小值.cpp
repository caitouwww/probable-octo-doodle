class Solution {
public:
    int findMin(vector<int>& nums) {
        /*int l=0,r=nums.size()-1;
        while(l<r)
        {
            int m=l+(r-l)/2;
            if(nums[m]>nums[r]) l=m+1;//nums[m]与nums[r]不会相等
            else    r=m;
        }
        return nums[l];*/
        //判断条件改为<=
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(nums[m]>=nums[r])    l=m+1;
            else r=m;
        }
        return nums[r];
        //先找最大值
        /*int l=0,r=nums.size()-1;
        while(l<r)
        {
            int m=l+(r-l+1)/2;
            if(nums[m]>nums[l]) l=m;
            else if(nums[m]<nums[l])    r=m-1;
        }
        return nums[(r+1)%nums.size()];*/
    }
};