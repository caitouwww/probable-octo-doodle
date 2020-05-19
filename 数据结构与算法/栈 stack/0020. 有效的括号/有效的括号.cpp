class Solution {
public:
    bool isValid(string s) 
    {
        /*vector<char> res;
        for(auto x:s)
        {
            if(x=='(')
            {
                res.push_back(x);
            }
            else if(x==')')
            {
                if(res.empty())
                {
                    return false;
                }
                else
                {
                    if(res[res.size()-1]!='(')
                    {
                        return false;
                    }
                    else
                    {
                        res.pop_back();
                    }
                }
            }
            else if(x=='[')
            {
                res.push_back(x);
            }
            else if(x==']')
            {
                if(res.empty())
                {
                    return false;
                }
                else
                {
                    if(res[res.size()-1]!='[')
                    {
                        return false;
                    }
                    else
                    {
                        res.pop_back();
                    }
                }
            }
            else if(x=='{')
            {
                res.push_back(x);
            }
            else if(x=='}')
            {
                if(res.empty())
                {
                    return false;
                }
                else
                {
                    if(res[res.size()-1]!='{')
                    {
                        return false;
                    }
                    else
                    {
                        res.pop_back();
                    }
                }
            }
        }
        return res.empty();*/
        if(s.size()%2)
        {
            return false;
        }
        vector<char> res;
        for(auto x:s)
        {
            if(x=='('||x=='['||x=='{')
            {
                res.push_back(x);
            }
            else if(x==')'||x==']'||x=='}')
            {
                if(res.empty())
                {
                    return false;
                }
                else
                {
                    char c = res[res.size()-1];
                    if((x==')'&&c=='(')||(x==']'&&c=='[')||(x=='}'&&c=='{'))
                    {
                        res.pop_back();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return res.empty();
    }
};