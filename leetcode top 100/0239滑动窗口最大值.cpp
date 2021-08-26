class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            if(!q.empty()&&q.front()<=i-k)q.pop_front();
            // while(!q.empty()&&nums[i]>=nums[q.back()])q.pop_back();
            while(!q.empty()&&nums[i]>nums[q.back()])q.pop_back();//维护递减双端队列
            q.push_back(i);
            if(i-k+1>=0)res.push_back(nums[q.front()]);
        }
        return res;
    }
};
