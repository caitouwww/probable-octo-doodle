class Solution {
public:
    int search_aux(vector<int>& nums,int low,int high,int target)
    {
        if(low>high)
            return -1;
        int mid=(low+high)/2;
        if(nums[mid]==target)
            return mid;
        /*if(nums[mid]<nums[high])
        {
            if(nums[mid]<target&&target<=nums[high])
                return search_aux(nums,mid+1,high,target);
            else
                return search_aux(nums,low,mid-1,target);
        }
        else
        {
            if(nums[low]<=target&&target<nums[mid])
                return search_aux(nums,low,mid-1,target);
            else
                return search_aux(nums,mid+1,high,target);
        }*/
        if(nums[low]<=nums[mid])//mid����ȡ������ֻ������Ԫ�ص�ʱ��mid==low���������=���ͻ���else��֧��©��
        {
            if(nums[low]<=target&&target<nums[mid])
                return search_aux(nums,low,mid-1,target);
            else
                return search_aux(nums, mid+1, high, target);
        }
        else
        {
            if(nums[mid]<target&&target<=nums[high])
                return search_aux(nums,mid+1,high,target);
            else
                return search_aux(nums,low,mid-1,target);
        }
    }
    int search(vector<int>& nums, int target) {
        return search_aux(nums,0,nums.size()-1,target);
    }
};