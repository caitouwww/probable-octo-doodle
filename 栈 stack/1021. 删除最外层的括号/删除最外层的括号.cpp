class Solution {
    public:
    string removeOuterParentheses(string S)
    {
        /*int l=0,r=0;
        int start=0,end=0;
        for(int i=0;i<S.size();i++)
        {
            end = i;
            if(S[i]=='(')
            {
                l++;
            }
            else if(S[i]==')')
            {
                r++;
            }
            if(l==r)
            {
                if(end-start==1)
                {
                    res+="";
                }
                else
                {
                    int k = start+1;
                    while(k<=end-1)
                    {
                        res+=S[k++];
                    }
                    
                }
                start=end+1;
            }
        }
        return res;*/
        int start=1,end=0;
        int i=1;
        while(i<S.size())
        {
            if(S[i]=='(')
            {
                start+=1;
            }
            else
            {
                end+=1;
            }
            if(start!=end)
            {
                res+=S[i];
            }
            else
            {
                start=1;
                end=0;
                i++;
            }
            i++;
        }
        return res;
    }
    private:
    string res="";
};