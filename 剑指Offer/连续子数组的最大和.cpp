class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() == 0)    return 0;
        vector<int> dp(array.size(), 0);
        int wholeMax = array[0];
        dp[0] = array[0];
        for(int i = 1; i < array.size(); i++){
            dp[i] = max(dp[i - 1], 0) + array[i];
            wholeMax = max(wholeMax, dp[i]);
        }
        return wholeMax;
    }
};