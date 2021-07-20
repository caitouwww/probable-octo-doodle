class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        vector<int> used(nums.size(),false);
        dfs(nums,tmp,used);
        return res;
    }
private:
    void dfs(vector<int>& nums,vector<int>&tmp,vector<int>&used){
        if(tmp.size()==nums.size()){
            res.emplace_back(tmp);
            return;
        }
        for(int i = 0; i < nums.size();++i){
            if(used[i])continue;
            else{
                used[i] = true;
                tmp.emplace_back(nums[i]);
                dfs(nums,tmp,used);
                tmp.pop_back();
                used[i] = false;
            }
        }
    }
private:
    vector<vector<int>> res;
};
