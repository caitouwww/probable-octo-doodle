class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0)
            return 0;
        int p=0,q=0;
        while(q<nums.size())
        {
            if(nums[q]==val)
            {
                q++;
            }
            else
            {
                nums[p]=nums[q];
                p++;
                q++;
            }
        }
        return p;
    }
};