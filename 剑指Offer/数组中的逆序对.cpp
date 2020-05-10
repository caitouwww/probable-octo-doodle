class Solution {
public:
    int InversePairs(vector<int> nums) {
        int n = nums.size();
        vector<int> tmp(n);
        long cnt = mergeSorts(nums, tmp, 0, n - 1);
        return cnt % 1000000007;
    }
    long mergeSorts(vector<int>& nums, vector<int>& tmp, int l, int r){
        if(l == r)  return 0;
        int mid = l + (r - l) / 2;
        long leftPairs = mergeSorts(nums, tmp, l, mid);
        long rightPairs = mergeSorts(nums, tmp, mid + 1, r);
        if(nums[mid] < nums[mid + 1])   return leftPairs + rightPairs;
        long crossPairs = mergeAndCount(nums, tmp, l, mid, r);
        return leftPairs + rightPairs + crossPairs;
    }
    long mergeAndCount(vector<int>& nums, vector<int>& tmp, int l, int mid, int r){
        for(int i = l; i <= r; i++){
            tmp[i] = nums[i];
        }
        int i = l;
        int j = mid + 1;
        long cnt = 0;
        for(int k = l; k <=r; k++){
            if(i == mid + 1){
                nums[k] = tmp[j];
                j++;
            }else if(j == r + 1){
                nums[k] = tmp[i];
                i++;
            }else if(tmp[i] <= tmp[j]){
                nums[k] = tmp[i];
                i++;
            }else{
                nums[k] = tmp[j];
                j++;
                cnt += (mid - i + 1);
            }
        }
        return cnt;
    }
};
