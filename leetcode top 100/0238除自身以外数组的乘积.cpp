class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> res1(n,1);
        // for(int i = 1; i < n; ++i){
        //     res1[i] = res1[i-1]*nums[i-1];
        // }
        // vector<int> res2(n,1);
        // for(int i = n-2; i >= 0; --i){
        //     res2[i] = res2[i+1]*nums[i+1];
        // }
        // vector<int> res(n,1);
        // for(int i = 0; i < n; ++i){
        //     res[i] = res1[i]*res2[i];
        // }
        // return res;


        // int n = nums.size();
        // vector<int> res(n,1);
        // int cur = 1;
        // for(int i = 1; i < n; ++i){
        //     cur = cur*nums[i-1];
        //     res[i] = cur;
        // }
        // cur = 1;
        // for(int i = n-2; i >= 0; --i){
        //     cur = cur*nums[i+1];
        //     res[i]*=cur;
        // }
        // return res;

        int left = 1;
        int right = 1;
        int n = nums.size();
        vector<int> res(n, 1);
        for(int i = 0; i < n; i++){
            res[i] = left;
            left *= nums[i];
        }
        for(int i = n - 1; i >= 0; i--){
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};
