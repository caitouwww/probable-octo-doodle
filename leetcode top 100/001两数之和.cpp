class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map<int,int> um;
        // vector<int> res;
        // int n = nums.size();
        // for(int i = 0; i < n; ++i){
        //     um[nums[i]] = i;
        // }
        // for(int i = 0; i < n; ++i){
        //     if(um[target-nums[i]]&&um[target-nums[i]]!=i){
        //         res.emplace_back(i);
        //         res.emplace_back(um[target-nums[i]]);
        //         break;
        //     }
        // }
        // return res;
        unordered_map<int,int> um;
        int n = nums.size();
        //注意这里不需要判断是否重复，因为对于每个x，首先查询是否存在target-x，不存在再插入x
        for(int i = 0; i < n; ++i){
            auto iter = um.find(target-nums[i]);
            if(iter!=um.end()){
                return {um[target-nums[i]],i};
            }
            um[nums[i]] = i;
        }
        return {};
    }
};
