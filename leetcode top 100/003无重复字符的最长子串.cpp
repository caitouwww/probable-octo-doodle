class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> um;
        int right = 0, n = s.size(), left = 0;
        int res = 0;
        while(right <n){
            um[s[right]]++;
            while(um[s[right]]>1){
                um[s[left]]--;
                left++;
            }
            res = max(res,right-left+1);
            right++;
        }
        return res;
    }
};
