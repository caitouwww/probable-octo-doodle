class Solution {
public:
    int search(vector<int>& nums, int l, int r)
    {
        if(l==r)
            return l;
        int m=l+(r-l)/2;
        if(nums[m]>nums[m+1])   return search(nums,l,m);
        return search(nums,m+1,r);
    }
    int findPeakElement(vector<int>& nums) {
        //自写
        // int l=0,r=nums.size()-1;
        // while(l<r)
        // {
        //     int m=l+(r-l)/2;
        //     if(m==0)
        //     {
        //         if(nums[m]>nums[m+1])   return m;
        //         else l=m+1;
        //     }
        //     else
        //     {
        //         if(nums[m]>nums[m-1]&&nums[m]>nums[m+1])    return m;
        //         else if(nums[m]>nums[m-1]&&nums[m]<nums[m+1])   l=m+1;
        //         else if(nums[m]<nums[m-1]&&nums[m]>nums[m+1])   r=m-1;
        //         else    r=m-1;
        //     }
        // }
        // return l;
        //从左往右，迭代二分查找
        // int l=0,r=nums.size()-1;
        // while(l<r)
        // {
        //     int m=l+(r-l)/2;
        //     if(nums[m]>nums[m+1]) r=m;
        //     else l=m+1;
        // }
        // return l;
        //从右往左
        // int l=0,r=nums.size()-1;
        // while(l<r)
        // {
        //     int m=l+(r-l+1)/2;
        //     if(nums[m]>nums[m-1])   l=m;
        //     else r=m-1;
        // }
        // return r;
        //线性扫描
        // for(int i=0;i<nums.size()-1;i++)
        // {
        //     if(nums[i]>nums[i+1])
        //         return i;
        // }
        // return nums.size()-1;
        //递归二分查找
        return search(nums,0,nums.size()-1);
    }
};