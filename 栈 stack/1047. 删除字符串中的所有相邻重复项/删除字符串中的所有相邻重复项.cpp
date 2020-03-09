class Solution {
public:
    string removeDuplicates(string S) {
        /*vector<char> vres;
        for(char x:S)
        {
            if(vres.empty())
            {
                vres.push_back(x);
            }
            else if(vres[vres.size()-1]==x)
            {
                vres.pop_back();
            }
            else
            {
                vres.push_back(x);
            }
        }
        string res;
        for(char x:vres)
        {
            res+=x;
        }
        return res;*/
        int top=0;
        string res;
        string::iterator it;
        for(char x:S)
        {
            if(top==0||res[top-1]!=x)
            {
                res+=x;
                top++;
            }
            else
            {
                res.erase(res.begin()+res.size()-1);
                top--;
            }
        }
        return res;
    }
};