//参考：https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        //二分查找，存在
        /*int low,high,mid;
        low = 0;
        high = nums.size();
        if(target<nums[0])
            return 0;
        else if(target>nums[nums.size()-1])
            return nums.size();
        else
        {//只适用存在的情况，或者不存在但该数在数组的取值范围之间的
            while(low<=high)
            {
                mid =low+(high-low)/2;
                if(nums[mid]<target)
                {
                    low = mid+1;
                }
                else if(nums[mid]>target)
                {
                    high = mid-1;
                }
                else
                {
                    return mid;
                }
            }
        }
        
        //不存在
        for(int i=0;i<nums.size()-1;i++)
        {
            if((nums[i]<target)&&(nums[i+1]>target))
            {
                return (i+1);
            } 
        }
        return 0;*/
        if(target>nums[nums.size()-1])
            return nums.size();
        int left = 0;
        int right = nums.size() - 1;
        while(left<right)
        {
            int mid = left +(right-left)/2;
            if(nums[mid]<target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};