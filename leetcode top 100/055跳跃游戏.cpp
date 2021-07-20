class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        int next = nums[0];
        for(int i = 1; i < n; ++i){
            if(next>=i)next=max(next,i+nums[i]);
            else return false;
        }
        return true;
    }
};
