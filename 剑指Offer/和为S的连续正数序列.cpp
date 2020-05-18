class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        if(sum <= 2)    return {};
        vector<vector<int> > rs;
        for(int l = 1, r = 1, s = 0; r <= sum / 2 + 1; r++){
            s += r;
            while(s > sum){
                s -= l;
                l++;
            }
            if(s == sum){
                vector<int> v;
                for(int i = l; i <= r; i++)    v.push_back(i);
                rs.push_back(v);
            }
        }
        return rs;
    }
};