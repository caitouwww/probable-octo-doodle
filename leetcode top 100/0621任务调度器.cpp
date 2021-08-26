class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       vector<int> nums(26,0);
       for(auto&x:tasks)nums[x-'A']++;
       sort(nums.rbegin(),nums.rend());
       int cnt = 1;
       while(cnt < nums.size()&& nums[cnt]==nums[0])cnt++;
       return max((int)tasks.size(),cnt+(n+1)*(nums[0]-1));
    }
};
