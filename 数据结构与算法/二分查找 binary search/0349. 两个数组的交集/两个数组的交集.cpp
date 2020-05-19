class Solution {
public:
    /*vector<int> intersectionOfTwoArrys(set<int>& st1,set<int>& st2)
    {
        vector<int> res;
        for(int val1:st1)
        {
            /*for(int val2:st2)
            {
                if(val1==val2)
                    res.push_back(val1);
            }*/
            //if(st2.count(val1)==1)
            /*if(st2.find(val1)!=st2.end())
                res.push_back(val1);
        }
        return res;
    }*/
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        /*set<int> st1(nums1.begin(),nums1.end());
        set<int> st2(nums2.begin(),nums2.end());
        if(st1.size()<st2.size())
        {
            return intersectionOfTwoArrys(st1,st2);
        }
        else
        {
            return intersectionOfTwoArrys(st2,st1);
        }
    }*/
    /*unordered_set<int> u;
    vector<int> res;
    for(int val: nums1)
    {
        u.insert(val);
    }
    for(int val:nums2)
    {
        auto a=u.find(val);
        if(a!=u.end())
        {
            res.push_back(val);
            u.erase(a);
        }
    }
    return res;*/
    unordered_set<int> u(nums1.begin(),nums1.end());
    vector<int> res;
    for(int val:nums2)
    {
        if(u.erase(val))
        {
            res.push_back(val);
        }
    }
    return res;
    }
};