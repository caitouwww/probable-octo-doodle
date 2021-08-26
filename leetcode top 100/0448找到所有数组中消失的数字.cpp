class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            int index = (abs(nums[i])-1);
            nums[index] = -abs(nums[index]);//标记index+1这个数出现过
        }
        vector<int> res;
        for(int i = 0; i < n; ++i){
            if(nums[i]>0)res.push_back(i+1);
        }
        return res;
    }
};
