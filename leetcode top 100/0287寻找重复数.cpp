class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(fast==slow)break;
        }
        int find = 0;
        while(true){
            find = nums[find];
            slow = nums[slow];
            if(find==slow)break;
        }
        return slow;
    }
};
