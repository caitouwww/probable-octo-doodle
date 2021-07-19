class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> um{{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},
        {'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        if(digits.empty())return res;
        string cur;
        dfs(digits,cur,um);
        return res;
    }
private:
    vector<string> res;
    void dfs(string digits,string cur,unordered_map<char,string>& um){
        if(!digits.size())res.emplace_back(cur);
        else{
            char c = digits[0];
            string s = um[c];
            int size = s.size();
            for(int i = 0; i < size; ++i){
                cur.push_back(s[i]);
                dfs(digits.substr(1),cur,um);
                cur.pop_back();
            }
        }
    }
};
