class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        int cur = 0;
        dfs(candidates,tmp,target,cur);
        return res;
    }
    void dfs(vector<int>& candidates,vector<int>& tmp,int target,int cur){
        if(target==0){
            res.emplace_back(tmp);
        }else if(target<0)return;
        else{
            for(int i = cur; i < candidates.size();++i){
                tmp.push_back(candidates[i]);
                dfs(candidates,tmp,target-candidates[i],i);
                tmp.pop_back();
            }
        }
    }
private:
    vector<vector<int>> res;
};
