class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*if(nums.size()==0)
            return 0;
        int element=nums[0];
        int length=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=element)
            {
                element=nums[i];
                length++;
                nums[length-1]=element;
            }
        }
        return length;*/
        if(nums.size()==0)
            return 0;
        int p=0,q=1;
        while(q<nums.size())
        {
            if(nums[q]==nums[p])
                q++;
            else
            {
                /*nums[p+1]=nums[q];
                p++;
                q++;*/
                if(q-p>1)
                {
                    nums[p+1]=nums[q];
                }
                p++,q++;
            }
        }
        return p+1;
    }
};