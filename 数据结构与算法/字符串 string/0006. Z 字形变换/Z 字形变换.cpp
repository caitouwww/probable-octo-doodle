class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> tmp(numRows);
        string res;
        int size = s.size();
        if(1 == numRows) return s;
        if(s.empty() || numRows < 1)   return res;
        for(int i = 0; i < size; i++){
            int ans = i / (numRows - 1);
            int cur = i % (numRows - 1);
            if(ans % 2 == 0){
                tmp[cur].push_back(s[i]);
            }else{
                tmp[numRows - 1 - cur].push_back(s[i]);
            }
        }
        for(int i = 0; i < tmp.size(); i++){
            res += tmp[i];
        }
        return res;
    }
};