class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*int res=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==res)
                count+=1;
            else
            {
                count-=1;
                if(count==0)
                {
                    res=nums[i+1];
                }
            }
        }
        return res;*/
        //超时
        /*int majorityCount=nums.size()/2;
        for(int i:nums)
        {
            int count=0;
            for(int j:nums)
            {
                if(i==j)
                    count+=1;
            }
            if(count>majorityCount)
                return i;
        }
        return -1;*/
        //Boyer-Moore投票算法
        /*int candidate=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==candidate)
                count++;
            else if(--count==0)
            {
                candidate=nums[i];
                count=1;
            }
        }
        return candidate;*/
        /*int candidate=-1;
        int count=0;
        for(int x:nums)
        {
            if(x==candidate)
                count++;
            else if(--count<0)
            {
                candidate=x;
                count=1;
            }
        }
        return candidate;*/
        //随机化
        /*while(true)
        {
            int candidate=nums[rand()%nums.size()];
            int count=0;
            for(int x:nums)
            {
                if(x==candidate)
                    count++;
            }
            if(count>nums.size()/2)
                return candidate;
        }
        return -1;*/
        //分治
        //return majority_element_rec(nums,0,nums.size()-1);
        //排序
        /*sort(nums.begin(),nums.end());
        return nums[nums.size()/2];*/
        //哈希表
        unordered_map<int,int> counts;
        int majority=0,cnt=0;
        for(int num:nums)
        {
            ++counts[num];
            if(counts[num]>cnt)
            {
                cnt=counts[num];
                majority=num;
            }
        }
        return majority;
    }
    /*int count_in_range(vector<int>& nums,int target,int low,int high)
    {
        int count=0;
        for(int i=low;i<=high;i++)
        {
            if(nums[i]==target)
                count++;
        }
        return count;
    }
    int majority_element_rec(vector<int>& nums,int low,int high)
    {
        if(low==high)
            return nums[low];
        int mid=(low+high)/2;
        int left_majority=majority_element_rec(nums,low,mid);
        int right_majority=majority_element_rec(nums,mid+1,high);
        if(count_in_range(nums,left_majority,low,high)>(high-low+1)/2)
            return left_majority;
        if(count_in_range(nums,right_majority,low,high)>(high-low+1)/2)
            return right_majority;
        return -1;
    }*/
};