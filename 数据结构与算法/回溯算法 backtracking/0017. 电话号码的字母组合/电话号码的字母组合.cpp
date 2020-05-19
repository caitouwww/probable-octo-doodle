class Solution {
public:
    // vector<string> letterCombinations(string digits) {
    //     unordered_map<char, string> table{
    //         {'0', " "}, {'1',"*"}, {'2', "abc"},
    //         {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
    //         {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"},
    //         {'9',"wxyz"}};
    //     vector<string> res;
    //     if(digits == "")    return res;
    //     dfs(res, "", digits, table, 0);
    //     return res;
    // }
    // void dfs(vector<string>& res, string str, string& digits, unordered_map<char, string>& m, int k){
    //     if(digits.size() == str.size()){
    //         res.push_back(str);
    //         return;
    //     }
    //     string tmp = m[digits[k]];
    //     for(char w : tmp){
    //         str += w;
    //         dfs(res, str, digits, m, k+1);
    //         str.pop_back();
    //     }
    //     return;
    // }
    map<char,string> mp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},  {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> res;
    string cur;
    vector<string> letterCombinations(string digits){
        if(!digits.size())
            return res;
        dfs(digits);
        return res;
    }
    void dfs(string digits){
        if(!digits.size())
            res.push_back(cur);
        else{
            char num = digits[0];
            string letter = mp[num];
            for(int i = 0; i < letter.size(); i++){
                cur.push_back(letter[i]);
                dfs(digits.substr(1));
                cur.pop_back();
            }
        }
    }
};
