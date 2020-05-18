class Solution {
public:
    string ReverseSentence(string str) {
        /*stack<string> st;
        int size = s.size();
        if(s == "")    return s;
        int j = 0;
        for(; j < size; j++){
            if(s[j] != ' ')    break;
        }
        string a = " ";
        if(j == size)    return a;
        int i = 0;
        string tmp;
        while(i < size){    
            if(s[i] != ' ') tmp += s[i];
            else{
                if(tmp != "")   st.push(tmp);
                tmp = "";
            }
            i++;
        }
        if(tmp != "")   st.push(tmp);
        string res;
        while(!st.empty()){
            res += st.top();
            if(st.size() > 1)   res += " ";
            st.pop();
        }
        return res;*/
        if(str.empty()) return str;
        int i = 0, sz = str.size();
        while(i < sz && str[i] == ' ') ++i;
        if (i == sz) return str;
        string ret = "";
        string tmp = "";
        bool hasstr = false;
        for (int i=sz-1; i>=0; --i) {
            // 合并一个单词
            if (str[i] != ' ') {
                tmp = str[i] + tmp;;
                hasstr = true;
            }
                // 找到一个单词，将单词合并到结果串中
            else if (str[i] == ' ' && hasstr) {
                ret = ret + tmp + " ";
                tmp = "";
                hasstr = false;
            }
        }
        if (tmp != "") 
            ret += tmp;
        return ret;
    }
};