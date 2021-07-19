class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)return;
        int i = n-1;
        for(;i>0;--i){
            if(nums[i]>nums[i-1]){
                int j = i;
                int index = i;
                while(j<n){
                    if(nums[j]>nums[i-1]&&nums[j]<nums[index]){
                        index = j;
                    }
                    j++;
                }
                swap(nums[index],nums[i-1]);
                sort(nums.begin()+i,nums.end());
                break;
                // if(index==i){
                //     swap(nums[i],nums[i-1]);
                //     sort(nums.begin()+i,nums.end());
                // }else{
                //     swap(nums[index],nums[i-1]);
                // }
            }
        }
        if(i==0)sort(nums.begin(),nums.end());
    }
};
