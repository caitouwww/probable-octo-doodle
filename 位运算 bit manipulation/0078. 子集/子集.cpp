class Solution {
public:
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     //位运算
    //     // vector<vector<int>> res;
    //     // res.push_back({});
    //     // int hash=1;
    //     // int size=pow(2,nums.size());
    //     // while(hash<size)
    //     // {
    //     //     vector<int> tmp;
    //     //     for(int k=0;k<nums.size();k++)
    //     //     {
    //     //         int a=1<<k;
    //     //         if(a&hash)
    //     //         {
    //     //             tmp.push_back(nums[k]);
    //     //         }
    //     //     }
    //     //     res.push_back(tmp);
    //     //     hash++;
    //     // }
    //     // return res;
    //     //层次遍历
    //     // vector<vector<int>> res(1);
    //     // for(int i=0;i<nums.size();i++)
    //     // {
    //     //     int cnt=res.size();
    //     //     for(int j=0;j<cnt;j++)
    //     //     {
    //     //         vector<int> tmp=res[j];
    //     //         tmp.push_back(nums[i]);
    //     //         res.push_back(tmp);
    //     //     }
    //     // }
    //     // return res;
        
    // }
    //回溯求解
    // void helper(vector<vector<int>>& res,vector<int> tmp,vector<int>& nums,int level)
    // {
    //     if(tmp.size()<=nums.size())
    //         res.push_back(tmp);
    //     for(int i=level;i<nums.size();i++)
    //     {
    //         tmp.push_back(nums[i]);
    //         helper(res,tmp,nums,i+1);
    //         tmp.pop_back();
    //     }
    // }
    // vector<vector<int>> subsets(vector<int>& nums)
    // {
    //     vector<vector<int>> res;
    //     vector<int> tmp;
    //     helper(res,tmp,nums,0);
    //     return res;
    // }
    //深度优先遍历求解
    void helper(vector<vector<int>>& res,vector<int> tmp,vector<int>& nums,int level)
    {
        if(level>=nums.size())
        {
            res.push_back(tmp);
            return;
        }
        tmp.push_back(nums[level]);
        helper(res,tmp,nums,level+1);
        tmp.pop_back();
        helper(res,tmp,nums,level+1);
    }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        helper(res,tmp,nums,0);
        return res;
    }
};