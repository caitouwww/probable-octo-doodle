class Solution {
public:
    bool isSubsequence(string s, string t) {
        /*int i=0,j=0;
        int lens=s.size(),lent=t.size();
        while(i<lens&&j<lent)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        if(i==lens)
        {
            return true;
        }
        else
        {
            return false;
        }*/
        /*if(s.size()==0)
            return true;
        int j=0;
        int len=s.size();
        for(int i=0;i<t.size();i++)
        {
            if(t[i]==s[j])
            {
                j++;
                if(j==len)
                {
                    return true;
                }
            }
            
        }
        return false;*/
        vector<vector<int>>dp(26);
        int tag=-1;
        for(int i=0;i<t.size();i++)
            dp[t[i]-'a'].push_back(i);
        for(int i=0;i<s.size();i++){
            int now=s[i]-'a';
            int left=0,right=dp[now].size()-1;
            while(left<right){
                int mid=(left+right)/2;
                if(dp[now][mid]>tag)
                    right=mid;
                else
                    left=mid+1;
            }
            if(right<left || dp[now][left]<tag)return false;
            tag=dp[now][left];
        
        }
        return true;
    }
};