// class Solution {
// public:
//     unordered_set<string> validExpressions;
//     int len;
//     vector<string> removeInvalidParentheses(string s) {
//         // unordered_set<string> us;
//         // us.insert(s);
//         // while(!us.empty()){
//         //     unordered_set<string> ans;
//         //     for(const string&st:us){
//         //         if(isValid(st)){
//         //             ans.insert(st);
//         //         }
//         //     }
//         //     if(!ans.empty())return vector<string>(ans.begin(),ans.end());
//         //     unordered_set<string> cur;
//         //     for(auto&st:us){
//         //         for(int i = 0; i < st.size(); ++i){
//         //             if(st[i]=='('||st[i]==')'){
//         //                 cur.insert(st.substr(0,i)+st.substr(i+1));
//         //             }
//         //         }
//         //     }
//         //     us = cur;
//         // }
//         // return vector<string>();
//         len = s.size();
//         int leftRemove = 0, rightRemove = 0;
//         for(int i = 0; i < len; ++i){
//             if(s[i]=='('){
//                 leftRemove++;
//             }else if(s[i]==')'){
//                 if(leftRemove==0)rightRemove++;
//                 if(leftRemove>0)leftRemove--;
//             }
//         }
//         string path;
//         dfs(s,0,0,0,leftRemove,rightRemove,path);
//         vector<string> ans;
//         for(auto iter = validExpressions.begin();iter!=validExpressions.end();++iter)ans.push_back(*iter);
//         return ans;
//     }
//     void dfs(string& s, int index, int leftCount, int rightCount, int leftRemove, int rightRemove, string path){
//         if(index==len){
//             if(leftRemove==0&&rightRemove==0){
//                 validExpressions.insert(path);
//             }
//             return;
//         }
//         char c = s[index];
//         //删除'('或')'
//         if(c=='('&&leftRemove>0){
//             dfs(s,index+1,leftCount,rightCount,leftRemove-1,rightRemove,path);
//         }
//         if(c==')'&&rightRemove>0){
//             dfs(s,index+1,leftCount,rightCount,leftRemove,rightRemove-1,path);
//         }
//         //保留当前字符
//         path.push_back(c);
//         if(c!='('&&c!=')'){
//             dfs(s,index+1,leftCount,rightCount,leftRemove,rightRemove,path);
//         }else if(c=='('){
//             dfs(s,index+1,leftCount+1,rightCount,leftRemove,rightRemove,path);
//         }else if(c==')'&&leftCount>rightCount){
//             dfs(s,index+1,leftCount,rightCount+1,leftRemove,rightRemove,path);
//         }
//         path.pop_back();

//     }
//     // bool isValid(string st){
//     //     int cnt = 0;
//     //     for(int i = 0; i < st.size(); ++i){
//     //         if(st[i]=='(')cnt++;
//     //         else if(st[i]==')')cnt--;
//     //         if(cnt<0)return false;
//     //     }
//     //     return cnt==0;
//     // }
// };
class Solution{
public:
    vector<string> removeInvalidParentheses(string s){
        int lcnt = 0, rcnt = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i]=='(')lcnt++;
            else if(s[i]==')'){
                if(lcnt==0)rcnt++;
                else lcnt--;
            }
        }
        if(lcnt==0&&rcnt==0)return {s};
        vector<string> ans;
        set<string> st;
        string str;
        dfs(s,str,0,lcnt,rcnt,0,0,st);
        return {st.begin(),st.end()};
    }
    void dfs(string& s, string& cur, int idx, int lcnt, int rcnt, int lnum, int rnum, set<string>& ans){
        if(idx==s.size()){
            if(lcnt==0&&rcnt==0)ans.insert(cur);
            return;
        }
        if(lnum<rnum)return;
        if(s[idx]=='('&&lcnt>0)dfs(s,cur,idx+1,lcnt-1,rcnt,lnum,rnum,ans);
        else if(s[idx]==')'&&rcnt>0)dfs(s,cur,idx+1,lcnt,rcnt-1,lnum,rnum,ans);
        if(s[idx]=='(')lnum++;
        else if(s[idx]==')')rnum++;
        cur.push_back(s[idx]);
        dfs(s,cur,idx+1,lcnt,rcnt,lnum,rnum,ans);
        cur.pop_back();
    }
};
