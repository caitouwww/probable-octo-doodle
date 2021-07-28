class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size())return "";
        int n = s.size();
        int right = 0;
        unordered_map<char,int> ums;
        unordered_map<char,int> umt;
        for(auto&x:t){
            umt[x]++;
        }
        int left = 0;
        int mleft = 0;
        int len = INT_MAX;
        while(right<n){
            ums[s[right]]++;
            while(check(ums,umt)){
                ums[s[left]]--;
                left++;
                if(right-left+2<len){
                    len = right-left+2;
                    mleft = left-1;
                }
            }
            right++;
        }
        if(len==INT_MAX)return "";
        return s.substr(mleft,len);
    }
    bool check(unordered_map<char,int>&ums,unordered_map<char,int>&umt){
        for(auto&x:umt){
            if(ums[x.first]<x.second)return false;
        }
        return true;
    }
};
