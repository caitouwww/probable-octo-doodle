class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        if(nums.size()<4)   return res;
        int size=nums.size();
        for(int a=0;a<size-3;a++)
        {
            if(a>0&&nums[a]==nums[a-1]) continue;
            for(int b=a+1;b<size-2;b++)
            {
                if(b>a+1&&nums[b]==nums[b-1])   continue;
                int c=b+1,d=size-1;
                while(c<d)
                {
                    int curSum=nums[a]+nums[b]+nums[c]+nums[d];
                    if(curSum<target)
                        c++;
                    else if(curSum>target)
                        d--;
                    else
                    {
                        res.push_back({nums[a],nums[b],nums[c],nums[d]});
                        c++;
                        d--;
                        while(c<d&&nums[c]==nums[c-1])  c++;
                        while(c<d&&nums[d]==nums[d+1])  d--;
                    }
                }
            }
        }
        return res;
    }
};