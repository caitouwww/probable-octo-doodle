class Solution {
public:
    int balancedStringSplit(string s) {
        int l=0,r=0;
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='R')
                r++;
            else if(s[i]=='L')
                l++;
            if(l==r)
            {
                l=r=0;
                res++;
            }
        }
        return res;
    }
};