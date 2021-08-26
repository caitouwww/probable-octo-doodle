class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        int cur = 0, res = 0;
        um[0] = 1;
        for(int i = 0; i < nums.size(); ++i){
            cur+=nums[i];
            if(um.count(cur-k))res+=um[cur-k];
            um[cur]++;
        }
        return res;
    }
};
