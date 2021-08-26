class Solution {
public:
    string decodeString(string s) {
        int len = s.size();
        int num = 0;
        stack<int> numstack;
        stack<string> strstack;
        string cur = "";
        for(int i = 0; i < len; ++i){
            if(isdigit(s[i])){
                num = 10*num + (s[i]-'0');
            }else if(s[i]=='['){
                numstack.push(num);
                strstack.push(cur);
                num = 0;
                cur.clear();
            }else if(isalpha(s[i])){
                cur+=s[i];
            }else if(s[i]==']'){
                int k = numstack.top();
                numstack.pop();
                string tmp = strstack.top();
                for(int i = 0; i < k; ++i){
                    tmp+=cur;
                }
                cur = tmp;
                strstack.pop();
                // strstack.push(tmp);
            }
        }
        return cur;
    }
};
