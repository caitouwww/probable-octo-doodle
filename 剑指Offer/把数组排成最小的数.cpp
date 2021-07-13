#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> v;
        for(auto x : numbers){
            v.push_back(to_string(x));
        }
        sort(v.begin(), v.end(), compare);
        string res;
        for(auto x : v){
            res += x;
        }
        return res;
    }
private:
    static bool compare(const string& a, const string& b){
        return a + b < b + a;
    }
};
int main(){
    Solution s = Solution();
    vector<int> v = {23,2};
    int res = s.PrintMinNumber(v);
    cout << res << endl;
    return 0;
}