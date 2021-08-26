class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // if(nums.empty()||k<1)return 0;
        // priority_queue<int,vector<int>,greater<int>> pq;
        // for(const auto&n:nums){
        //     if(pq.size()>k){
        //         pq.pop();
        //         if(n>=pq.top()){
        //             pq.pop();
        //             pq.push(n);
        //         }
        //     }else{
        //         if(pq.size()==k){
        //             if(n>=pq.top()){
        //                 pq.pop();
        //                 pq.push(n);
        //             }
        //         }else{
        //             pq.push(n);
        //         }
        //     }
        // }
        // return pq.top();
        // priority_queue<int,vector<int>,greater<int>> pq;
        // for(auto&x:nums){
        //     pq.push(x);
        //     if(pq.size()>k)pq.pop();
        // }
        // return pq.top();
        int n = nums.size();
        int left = 0, right = n - 1;
        int target = n - k;
        while(true){
            int index = partition(nums,left,right);
            if(index==n-k)return nums[index];
            else if(index<n-k)left = index+1;
            else right = index-1;
        }
        return 0;
    }
    int partition(vector<int>& nums,int left, int right){
        int pivot = nums[left];
        int j = left;
        for(int i = left + 1; i <=right; ++i){
            if(nums[i]<pivot){
                ++j;
                swap(nums,i,j);
            }
        }
        swap(nums,left,j);
        return j;
    }
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
