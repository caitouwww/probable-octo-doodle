class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> a,int sum) {
        int size = a.size();
        int multiply = INT_MAX;
        vector<int> res(2, 0);
        int flag = 0;
        for(int l = 0, r = size - 1, s = 0; l < r;){
            s = a[l] + a[r];
            if(s > sum)    r--;
            else if(s < sum) l++;
            else{
                flag = 1;
                if(a[l] * a[r] < multiply){
                    res[0] = a[l];
                    res[1] = a[r];
                    multiply = a[l] * a[r];
                }
                l++;
                r--;
            }
        }
        if(flag == 1)    return res;
        else return {};
    }
};