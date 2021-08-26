// class Solution {
// public:
//     set<pair<int,int>> st;
//     int countSubstrings(string s) {
//         int n = s.size();
//         for (int i = 0; i < n; ++i) {
//             help(s,i);
//         }
//         return st.size();
//     }
//     void help(string& s, int start){
//         int l = start, r = start;
//         while(l>=0&&r<s.size()&&s[l]==s[r]){
//             st.insert(make_pair(l,r));
//             l--;
//             r++;
//         }
//         l = start, r = start+1;
//         while(l>=0&&r<s.size()&&s[l]==s[r]){
//             st.insert(make_pair(l, r));
//             l--;
//             r++;
//         }
//     }
// };
class Solution{
public:
    int cnt = 0;
    int countSubstrings(string s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            count(s,i,i);
            count(s,i,i+1);
        }
        return cnt;
    }
    void count(string& s, int start, int end) {
        while (start >= 0 && end <= s.size()-1 && s[start] == s[end]) {
            cnt++;
            start--;
            end++;
        }
    }
};
