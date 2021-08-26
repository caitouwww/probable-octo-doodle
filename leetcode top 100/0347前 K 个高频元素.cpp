class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> freq;
        for(auto&x:nums)freq[x]++;
        using pii = pair<int,int>;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(auto& f:freq){
            pq.emplace(f.second,f.first);
            if(pq.size()>k)pq.pop();
        }
        while(!pq.empty()){
            res.emplace_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
