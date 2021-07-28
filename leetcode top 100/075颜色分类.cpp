class Solution {
public:
    void sortColors(vector<int>& nums) {
        int last = nums.size() - 1;
        int cur = 0;
        int front = 0;
        while(cur<=last){
            if(nums[cur]==0)swap(nums[cur++],nums[front++]);
            else if(nums[cur]==2)swap(nums[cur],nums[last--]);
            else cur++;
        }
    }
};
