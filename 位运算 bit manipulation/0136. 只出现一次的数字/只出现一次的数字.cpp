#include <vector>
#include <set>
#include <map>
#include <numeric>//accumulate
#include <iostream>
using namespace std;
class Solution
{public:
    int singleNumber(vector<int>& nums)
    {
        //列表操作
        // multiset<int> st;
        // for(int x:nums)
        // {
        //     auto res = st.find(x);
        //     if(res==st.end())
        //     {
        //         st.insert(x);
        //     }
        //     else
        //     {
        //         st.erase(x);
        //     }     
        // }
        // return *st.begin();
        //哈希表
        // map<int,int> res;
        // for(int x:nums)
        // {
        //     auto tmp=res.find(x);
        //     if(tmp==res.end())
        //     {
        //         res[x]=1;
        //     }
        //     else
        //     {
        //         res.erase(x);
        //     }
        // }
        // return res.begin()->first;
        //数学方法
        // set<int> st(nums.begin(),nums.end());
        // int suma=accumulate(st.begin(),st.end(),0);
        // int sumb=accumulate(nums.begin(),nums.end(),0);
        // return 2*suma-sumb;
        //异或操作
        int res=0;
        for(int x:nums)
        {
            res^=x;
        }
        return res;
    }

};