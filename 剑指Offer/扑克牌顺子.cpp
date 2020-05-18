class Solution {
public:
    bool IsContinuous( vector<int> nums ) {
        sort(nums.begin(), nums.end());
        int size = nums.size(), zeros = 0;
        if(size == 0)    return false;
        for(int i = 0; i < size; i++){
            if(nums[i] == 0)    zeros++;
            else    break;
        }
        for(int i = zeros; i < size - 1; i++){
            if(nums[i] == nums[i + 1])    return false;
            else if(nums[i] != nums[i + 1] - 1){
                int tmp = nums[i + 1] - nums[i];
                zeros -= tmp - 1;
                if(zeros < 0)    return false;
            }
        }
        return true;
    }
};