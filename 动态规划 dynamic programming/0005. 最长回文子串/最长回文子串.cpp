class Solution {
public:
    //超时
    // bool isPalindrome(string s)
    // {
    //     int len=s.size();
    //     int l=0,r=len-1;
    //     while(l<r)
    //     {
    //         if(s[l]!=s[r])
    //             return false;
    //         l++;
    //         r--;
    //     }
    //     return true;
    // }
    // string longestPalindrome(string s)
    // {
    //     int max=0;
    //     int size=s.size();
    //     string ret;
    //     for(int i=0;i<size;i++)
    //     {
    //         for(int j=i;j<size;j++)
    //         {
    //             string res=string(s.begin()+i,s.begin()+j+1);
    //             if(isPalindrome(res))
    //             {
    //                 int len=j-i+1;
    //                 if(len>max)
    //                 {
    //                     max=len;
    //                     ret=res;
    //                 }
    //             }
    //         }
    //     }
    //     return ret;
    // }
    //动态规划
    // string longestPalindrome(string s)
    // {
    //     if(s.empty())
    //         return s;
    //     int size=s.size();
    //     vector<vector<bool>> dp(size,vector<bool>(size));
    //     //1字母初始化
    //     for(int i=0;i<size;i++)
    //     {
    //         dp[i][i]=true;
    //     }
    //     //2字母初始化 P(i,i+1)=(S[i]==S[i+1])
    //     for(int i=0;i<size-1;i++)
    //     {
    //         dp[i][i+1]=(s[i]==s[i+1]);
    //     }

    //     int left=0,right=0,max=1;
    //     for(int i=size-2;i>=0;i--)
    //     {
    //         for(int j=i+1;j<size;j++)
    //         {
    //             // P(i,j)=(P(i+1,j?1) and Si==Sj)
    //             if(j!=i+1)
    //             {
    //              dp[i][j]=dp[i+1][j-1]&&(s[i]==s[j]);
    //             }
    //             if(dp[i][j]&&max<j-i+1)
    //             {
    //                 max=j-i+1;
    //                 left=i;
    //                 right=j;
    //             }
    //         }
    //     }
    //     return s.substr(left,right-left+1);
    // }
    //中心扩展算法
    int expandAroundCenter(string s,int left,int right)
    {
        int L=left,R=right;
        while(L>=0&&R<s.size()&&s[L]==s[R])
        {
            L--;
            R++;
        }
        return R-L-1;
    }
    string longestPalindrome(string s)
    {
        if(s.empty())   return s;
        int start=0,end=0;
        for(int i=0;i<s.size();i++)
        {
            int len1=expandAroundCenter(s,i,i);
            int len2=expandAroundCenter(s,i,i+1);
            int len=max(len1,len2);
            if(len>end-start)
            {
                start=i-(len-1)/2;
                end=i+len/2;
            }
        }
        return s.substr(start,end-start+1);
    }

};