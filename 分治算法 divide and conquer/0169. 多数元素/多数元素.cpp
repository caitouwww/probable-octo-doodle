class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //排序
        /*sort(nums.begin(),nums.end());
        return nums[nums.size()/2];*/
        //Boyer-Moore投票算法
        /*int candidate=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==candidate)
                count++;
            else
            {
                count--;
                if(count==0)
                {
                    candidate=nums[i];
                    count=1;
                }
            }
        }
        return candidate;*/
        //随机化
        /*while(true)
        {
            int candidate=nums[rand()%nums.size()];
            int cnt=0;
            for(int i=0;i<nums.size();i++)
            {
                if(candidate==nums[i])
                {
                    cnt++;
                }
                if(cnt>nums.size()/2)
                {
                    return candidate;
                }
            }
        }
        return -1;*/
        //分治
        //return majorityElementRec(nums,0,nums.size()-1);
        //哈希表
        unordered_map<int,int> counts;
        int majority=0,cnt=0;
        for(int val:nums)
        {
            ++counts[val];
            if(counts[val]>cnt)
            {
                cnt=counts[val];
                majority=val;
            }
        }
        return majority;
    }
    /*int majorityElementRec(vector<int>& nums,int start,int end)
    {
        if(start==end)
            return nums[start];
        int mid=(start+end)/2;
        int leftMajority=majorityElementRec(nums,start,mid);
        int rightMajority=majorityElementRec(nums,mid+1,end);

        if(countInRange(nums,leftMajority,start,end)>(end-start+1)/2)
            return leftMajority;
        if(countInRange(nums,rightMajority,start,end)>(end-start+1)/2)
            return rightMajority;
        return -1;
    }
    int countInRange(vector<int>& nums,int target,int start,int end)
    {
        int cnt=0;
        for(int i=start;i<=end;i++)
        {
            if(nums[i]==target)
                cnt++;
        }
        return cnt;
    }*/
};