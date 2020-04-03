class Solution {
public:
    /*int searchFirst(vector<int>& nums, int left, int right, int target)
    {
        while(left<right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid]<target)
                left=mid+1;
            else
                right=mid;
        }
        if(nums[left]==target)  return left;
        return -1;
    }
    int searchLast(vector<int>& nums, int left, int right, int target)
    {
        while(left<right)
        {
            int mid = left + (right - left + 1)/2;
            if(nums[mid]>target)
                right=mid-1;
            else
                left=mid;
        }
        if(nums[right]==target) return right;
        return -1;
    }*/
    vector<int> searchRange(vector<int>& nums, int target) {
		//��д
        /*vector<int> res(2,-1);
        if(nums.size()==0)  return res;
        int a=searchFirst(nums,0,nums.size()-1,target);
        int b=searchLast(nums,0,nums.size()-1,target);
        if(a!=-1)   res[0]=a;
        if(b!=-1)   res[1]=b;
        return res;*/
        vector<int> res(2,-1);
        if(nums.empty()) return res;
        int n=nums.size(),l=0,r=n-1;
        while(l<r)
        {
            int m=l+(r-l)/2;
            if(nums[m]>=target) r=m;
            else    l=m+1;
        }
        if(nums[l]!=target) return res;
        res[0]=l;
        r=n;//��֮ͬ������̫��Ҫ��������
        while(l<r)
        {
            int m=l+(r-l)/2;
            if(nums[m]<=target)   l=m+1;//�㲻��
            else r=m;
        }
        res[1]=l-1;
        return res;
    }
};