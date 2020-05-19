class Solution {
public:
    //self code
    // vector<vector<int>> res;
    // set<vector<int>> s;
    // vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    //     vector<int> tmp;
    //     sort(candidates.begin(), candidates.end());
    //     dfs(candidates, tmp, target, 0, 0);
    //     return res;
    // }
    // void dfs(vector<int>& candidates, vector<int>& tmp, int target, int sum, int begin){
    //     if(sum == target){
    //         auto iter = s.find(tmp);
    //         if(iter == s.end()){
    //             res.push_back(tmp);
    //             s.insert(tmp);
    //             return;
    //         }
    //     }else{
    //         for(int i = begin; i < candidates.size(); i++){
    //             if(sum + candidates[i] <= target){
    //                 tmp.push_back(candidates[i]);
    //                 dfs(candidates, tmp, target, sum + candidates[i], i + 1);
    //                 tmp.pop_back();
    //             }
    //         }
    //     }
    // }
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, tmp, target, 0, 0);
        return res;
    }
    void dfs(vector<int>& candidates, vector<int>& tmp, int target, int sum, int begin){
        if(sum == target){
            res.push_back(tmp);
            return;
        }else{
            for(int i = begin; i < candidates.size(); i++){
                //去重，避免相同的情况筛选两次，一次原生for循环，一次递归
                if(i > begin && candidates[i] == candidates[i - 1]){
                    continue;
                }
                if(sum + candidates[i] <= target){
                    tmp.push_back(candidates[i]);
                    dfs(candidates, tmp, target, sum + candidates[i], i + 1);
                    tmp.pop_back();
                }
            }
        }
    }
};
