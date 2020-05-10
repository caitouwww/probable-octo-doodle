class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.size() == 0)    return res;
        sort(input.begin(), input.end());
        if(k > input.size())    return res;
        if(k == input.size())    return input;
        int i = 0;
        while(k--){
            res.push_back(input[i]);
            while(input[i + 1] == input[i])    i++;
            i++;
        }
        return res;
    }
};
