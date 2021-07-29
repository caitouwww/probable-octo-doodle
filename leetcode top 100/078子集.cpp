class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        int len = 0;
        dfs(nums,len,cur);
        return res;
    }
    void dfs(vector<int>&nums,int len,vector<int>&cur){
        res.emplace_back(cur);
        for(int i = len; i < nums.size(); ++i){
            cur.push_back(nums[i]);
            dfs(nums,i+1,cur);
            cur.pop_back();
        }
    }
private:
    vector<vector<int>> res;
};
