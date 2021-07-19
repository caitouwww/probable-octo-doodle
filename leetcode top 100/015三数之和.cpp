class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int target;
        vector<vector<int>> res;
        for(int i = 0; i < n; ++i){
            if(i>0&&nums[i]==nums[i-1])continue;
            if((target=nums[i])>0)break;
            int l = i+1, r = n - 1;
            while(l<r){
                int sum = nums[l]+nums[r]+target;
                if(sum>0)r--;
                else if(sum<0)l++;
                else{
                    // vector<int> tmp{target,nums[l],nums[r]};
                    // res.emplace_back(tmp);
                    res.push_back({target,nums[l],nums[r]});
                    l++,r--;
                    while(l<r&&nums[l]==nums[l-1])l++;
                    while(l<r&&nums[r]==nums[r+1])r--;
                }
            }
        }
        return res;
    }
};
