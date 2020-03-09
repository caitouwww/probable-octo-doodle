class Solution {
public:
    void getStackValue(string& s,vector<char>& a)
    {
        for(char x:s)
        {
            if(x=='#')
            {
                if(!a.empty())
                {
                    a.pop_back();
                }
            }
            else
            {
                a.push_back(x);
            }
        }
    }
    bool backspaceCompare(string S, string T) {
        /*for(char x:S)
        {
            if(x=='#')
            {
                if(!a.empty())
                {
                    a.pop_back();
                }
            }
            else
            {
                a.push_back(x);
            }
            
        }
        for(char x:T)
        {
            if(x=='#')
            {
                if(!b.empty())
                {
                    b.pop_back();
                }
            }
            else
            {
                b.push_back(x);
            }
            
        }
        return a==b;*/
        //getStackValue(S,a);
        //getStackValue(T,b);
        //return a==b;
		int i=S.size()-1;
        int j=T.size()-1;
        int skipS=0,skipT=0;
        while(i>=0 || j>=0)
        {
            while(i>=0)
            {
                if(S[i]=='#')
                {
                    skipS++;i--;
                }
                else if(skipS>0)
                {
                    skipS--;i--;
                }
                else
                {
                    break;
                }
            }
            while(j>=0)
            {
                if(T[j]=='#')
                {
                    skipT++;j--;
                }
                else if(skipT>0)
                {
                    skipT--;j--;
                }
                else
                {
                    break;
                }
            }
            if(i>=0 && j>=0 && S[i]!=T[j])
                return false;
            if((i>=0)!=(j>=0))
                return false;
            i--;j--;
        }
        return true;
}
private:
vector<char> a;
vector<char> b;
};