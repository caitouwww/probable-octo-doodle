class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        vector<bool> flag(nums.size(), false);
        dfs(nums, tmp, 0, flag);
        return res;
    }
    void dfs(vector<int>& nums, vector<int>& tmp, int k, vector<bool>& flag){
        if(tmp.size() == nums.size()){
            res.push_back(tmp);
            return;
        }else{
            for(int i = 0; i < nums.size(); i++){
                if(!flag[i]){
                    flag[i] = true;
                    tmp.push_back(nums[i]);
                    dfs(nums, tmp, k + 1, flag);
                    tmp.pop_back();
                    flag[i] = false;
                }
            }
        }
    }
};
