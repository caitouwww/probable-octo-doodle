class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int right = 0, n = intervals.size();
        int small = INT_MAX, big = INT_MIN;
        vector<vector<int>> res;
        while(right < n){
            int first = intervals[right][0], second = intervals[right][1];
            if(right==0){
                small = first;
                big = second;
            }else{
                if(first<=big){
                    small = min(small,intervals[right][0]);
                    big = max(big,intervals[right][1]);
                }else{
                    res.push_back({small,big});
                    small = first;
                    big = second;
                }
            }
            right++;
        }
        res.push_back({small,big});
        return res;
    }
};
