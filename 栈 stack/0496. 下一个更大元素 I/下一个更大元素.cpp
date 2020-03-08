#include <stack>
#include <vector>
#include <map>
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        /*vector<int> res;
        int j;
        int i;
        for(auto x:nums1)
        {
            for(i = 0;i<nums2.size();i++)
            {
                if(nums2[i]==x)
                {
                    j = i;
                    while(nums2[j]<=x)
                    {
                        if(j<nums2.size()-1)
                            j++;
                        else
                            break;
                    }
                    if(nums2[j]>x)
                    {
                        res.push_back(nums2[j]);
                    }
                    else
                    {
                        res.push_back(-1);
                    }
                    break;
                }
            }
        }
        return res;*/
        stack<int> s;
        vector<int> ans(nums2.size());
        vector<int> res;
        map<int,int> m;
        for(int i = nums2.size()-1;i>=0;i--)
        {
            while(!s.empty()&&s.top()<=nums2[i])
                s.pop();
            ans[i] = s.empty()?-1:s.top();
            m.insert(make_pair(nums2[i],ans[i]));
            s.push(nums2[i]);
        }
        for(int val:nums1)
        {
            res.push_back(m[val]);
        }
        return res;
    }
};