class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        dfs(candidates, tmp, target, 0, 0);
        return res;
    }
    void dfs(vector<int>& candidates, vector<int>& tmp, int target, int sum, int begin){
        if(sum == target){
            res.push_back(tmp);
        }else{
            for(int i = begin; i < candidates.size(); i++){
                if(sum + candidates[i] <= target){
                    tmp.push_back(candidates[i]);
                    dfs(candidates, tmp, target, sum + candidates[i], i);
                    tmp.pop_back();
                }
            }
        }
    }
};
