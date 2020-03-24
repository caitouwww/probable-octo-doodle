class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        map<int,vector<int>> res;
        for(int val:arr)
        {
            res[count1(val)].push_back(val);
        }
        vector<int> vres;
        for(auto iter=res.begin();iter!=res.end();iter++)
        {
            for(auto i:iter->second)
            {
                vres.push_back(i);
            }
        }
        return vres;
    }
    int count1(int num)
    {
        int cnt=0;
        while (num)
        {
            cnt++;
            num=num&(num-1);
        }
        return cnt;
    }
};