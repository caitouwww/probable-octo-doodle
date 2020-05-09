class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        vector<bool> flag(nums.size(), false);
        dfs(nums, tmp, flag);
        return res;
    }
    void dfs(vector<int>& nums, vector<int>& tmp, vector<bool>& flag)
    {
        if(tmp.size() == nums.size()){
            res.push_back(tmp);
            return;
        }else{                                                                                               for(int i = 0; i < nums.size(); i++){
                if(!flag[i]){
                    if(i > 0 && nums[i] == nums[i - 1] && flag[i - 1] == true)  continue;
                    flag[i] = true;
                    tmp.push_back(nums[i]);
                    dfs(nums, tmp, flag);
                    tmp.pop_back();
                    flag[i] = false;
                }
            }
        }
    }
};
