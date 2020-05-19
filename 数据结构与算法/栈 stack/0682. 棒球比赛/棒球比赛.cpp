#include <string>
#include <vector>
#include <numeric>
class Solution {
public:
    int calPoints(vector<string>& ops)
    {
        for(string s:ops)
        {
             char c = s[s.size()-1];
             if(isdigit(c))
             {
                 res.push_back(stoi(s));
             }
             else if(c=='D')
             {
                 res.push_back(2*res[res.size()-1]);
             }
             else if(c=='C')
             {
                 res.pop_back();
             }
             else if(c=='+')
             {
                 res.push_back(res[res.size()-2]+res[res.size()-1]);
             }
        }
        int ans=accumulate(res.begin(),res.end(),0);
        return ans;
    }
    private:
    vector<int> res;
};