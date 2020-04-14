class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        //超时
        // int size=nums.size();
        // int res=INT_MAX;
        // for(int i=0;i<size;i++){
        //     if(nums[i]>=s)  return 1;
        //     int sum=0;
        //     for(int j=i;j<size;j++){
        //         sum+=nums[j];
        //         if(sum>=s)  res=min(res,j-i+1);
        //     }
        // }
        // if(res!=INT_MAX)    return res;
        // else    return 0;
        //自写，双指针
        // int size = nums.size();
        // int sum = 0;
        // int res = INT_MAX;
        // int front = 0;
        // for(int i = 0; i < size; i++){
        //     if(nums[i] >= s)    return 1;
        //     sum += nums[i];
        //     if(sum >= s){
        //         while(sum >= s){
        //             sum -= nums[front++];
        //         }
        //         res = min(res, i - front + 2);
        //     }
        // }
        // if(res != INT_MAX)  return res;
        // else    return 0;
        //使用二分查找https://leetcode-cn.com/problems/minimum-size-subarray-sum/solution/chang-du-zui-xiao-de-zi-shu-zu-by-leetcode/
        int size = nums.size();
        if(size == 0)  return 0;
        int ans = INT_MAX;
        vector<int> sums(size + 1, 0);
        for(int i = 1; i <= size; i++)   sums[i] = sums[i - 1] + nums[i - 1];
        for(int i = 1; i<= size; i++){
            int to_find = s + sums[i - 1];
            auto bound = lower_bound(sums.begin(), sums.end(), to_find);
            if(bound != sums.end()){
                ans = min(ans, static_cast<int> (bound - (sums.begin() + i - 1)));
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};
