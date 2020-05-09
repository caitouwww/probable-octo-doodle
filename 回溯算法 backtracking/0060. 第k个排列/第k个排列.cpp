class Solution {
public:
    // //超时，回溯
    // string res;
    // string getPermutation(int n, int k) {
    //     string tmp;
    //     vector<bool> flag(n, false);
    //     dfs(n, tmp, flag, k);
    //     return res;
    // }
    // void dfs(int n, string& tmp, vector<bool>& flag, int& k){
    //     if(tmp.size() == n){
    //         k--;
    //         if(!k){
    //             res = tmp;
    //         }
    //         return;
    //     }else{
    //         for(int i = 1; i <= n; i++){
    //             if(!flag[i - 1]){
    //                 flag[i - 1] = true;
    //                 tmp += char(i - 0 + '0');
    //                 dfs(n, tmp, flag, k);
    //                 tmp.pop_back();
    //                 flag[i - 1] = false;
    //             }
    //             if(!k)  return;
    //         }
    //     }
    // }
    string getPermutation(int n, int k){
        // string res;
        // vector<int> candidates(n);
        // //分母的阶乘数
        // vector<int> factorials(n + 1, 1);
        // for(int i = 1; i <= n ; i++){
        //     candidates[i - 1] = i;
        //     factorials[i] = factorials[i - 1] * i;
        // }
        // k -= 1;
        // for(int i = n - 1; i >= 0; i--){
        //     int index = k / factorials[i];
        //     res.push_back(candidates[index] + '0');
        //     candidates.erase(candidates.begin() + index);
        //     // res.push_back(index + 1 + '0');
        //     k -= index * factorials[i];
        // }
        // return res;
        //康拓展开
        vector<char> chs{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        const int factor[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        string str;
        for(--k; n--; k %= factor[n]){
            const int i = k / factor[n];
            str.push_back(chs[i]);
            chs.erase(chs.begin() + i);
        }
        return str;
    }
};
