class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // if(nums.empty())return 0;
        // map<int,int> m;
        // for(auto&x:nums)m[x]++;
        // int res = 0;
        // map<int,int> dp;
        // int mi = *min_element(nums.begin(),nums.end());
        // int ma = *max_element(nums.begin(),nums.end());
        // priority_queue<int,vector<int>,greater<int>> pq;
        // for(auto&x:nums)pq.push(x);
        // while(!pq.empty()){
        //     int i = pq.top();
        //     pq.pop();
        //     if(m.count(i-1)&&m.count(i))dp[i] = dp[i-1]+1;
        //     else if(m.count(i))dp[i] = 1;
        //     else dp[i] = 0;
        //     res = max(res,dp[i]);
        // }
        // return res;

        // unordered_map<int,int> um;
        // int res = 0;
        // for(auto&x:nums){
        //     if(um.count(x))continue;
        //     int left = 0, right = 0;
        //     if(um.count(x-1))left = um[x-1];
        //     if(um.count(x+1))right = um[x+1];
        //     int cur = left+right+1;
        //     res = max(res,cur);
        //     um[x] = cur;
        //     um[x-left] = cur;
        //     um[x+right] = cur;
        // }
        // return res;

        unordered_set<int> us;
        for(const int& n:nums)us.insert(n);
        int res = 0;
        for(const int& n:us){
            if(!us.count(n-1)){
                int tmp = n;
                int len = 1;
                while(us.count(++tmp))len++;
                res = max(res,len);
            }
        }
        return res;
    }
};
