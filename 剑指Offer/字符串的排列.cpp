class Solution {
public:
    vector<string> res;
    vector<string> Permutation(string str) {
        if(str.size() == 0)    return res;
        string tmp;
        sort(str.begin(), str.end());
        vector<bool> flag(str.size(), false);
        dfs(str, tmp, flag);
        return res;
    }
    void dfs(string& str, string& tmp, vector<bool>& flag){
        if(str.size() == tmp.size()){
            res.push_back(tmp);
            return;
        }else{
            for(int i = 0; i < str.size(); i++){
                if(!flag[i]){
                    if(i > 0 && str[i] == str[i - 1] && flag[i - 1] == false)    continue;
                    flag[i] = true;
                    tmp += str[i];
                    dfs(str, tmp, flag);
                    tmp.pop_back();
                    flag[i] = false;
                }
            }
        }
    }
};
