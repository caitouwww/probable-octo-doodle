class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size())return {};
        vector<int> freqs(26,0), freqp(26,0);
        int r = 0;
        for(int i = 0; i < p.size(); ++i){
            freqp[p[i]-'a']++;
            freqs[s[r++]-'a']++;
        }
        vector<int> res;
        if(freqp==freqs)res.push_back(0);
        while(r<s.size()){
            freqs[s[r-p.size()]-'a']--;
            freqs[s[r++]-'a']++;
            if(freqs==freqp)res.push_back(r-p.size());
        }
        return res;
    }
};
