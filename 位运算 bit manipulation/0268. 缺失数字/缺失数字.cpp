class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*long res=0;
        for(int val:nums)
        {
            res+=val;
        }
        return (0+nums.size())*(nums.size()+1)/2-res;*/
        /*long res=0;
        for(int i=0;i<nums.size();i++)
        {
            res+=(i-nums[i]);
        }
        return res+nums.size();*/
        /*int res=nums.size();
        int i=0;
        for(int val:nums)
        {
            res^=(val^(i++));
        }
        return res;*/
        //ÅÅÐò
        /*sort(nums.begin(),nums.end());
        if(nums[0]!=0)
            return 0;
        if(nums[nums.size()-1]!=nums.size())
            return nums.size();
        for(int i=1;i<nums.size();i++)
        {
            int expectNum=i;
            if(expectNum!=nums[i])
                return expectNum;
        }
        return -1;*/
        /*if(nums.size()==0)
            return 0;
        int n=nums.size()+1;
        int sum=n*(n-1)/2;
        for(int val:nums)
            sum-=val;
        return sum;*/
        /*int res=0;
        for(int i=1,size=nums.size();i<=size;i++)
        {
            res+=(i-nums[i-1]);
        }
        return res;*/
        //¹þÏ£±íÔõÃ´Ð´£¿£¿
        map<int,int> m;
        for(int val:nums)
            m[val]=1;
        for(int i=0;i<=nums.size();i++)
        {
            if(m.find(i)==m.end())
                return i;
        }
        return -1;
    }
};