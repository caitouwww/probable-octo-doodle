class Solution {
public:
    // string largestNumber(vector<int>& nums) {
    //     if(!nums.size())    return "";
    //     vector<string> vec;
    //     for(int num : nums){
    //         vec.push_back(to_string(num));
    //     }
    //     sort(vec.begin(), vec.end(), cmp);
    //     stringstream ss;
    //     string res;
    //     for(string str : vec){
    //         ss << str;
    //     }
    //     ss >> res;
    //     return res[0] == '0' ? "0" : res;
    // }
    // static bool cmp(const string& a, const string& b){
    //     return a + b > b + a;
    // }
    //归并排序
    vector<string> tmp;
    string largestNumber(vector<int>& nums){
        if(!nums.size())    return "";
        vector<string> vec;
        for(int num : nums){
            vec.push_back(to_string(num));
        }
        tmp.resize(vec.size());
        mysort(vec, 0, vec.size() - 1);
        stringstream ss;
        string res;
        for(string str : vec){
            ss << str;
        }
        ss >> res;
        return res[0] == '0' ? "0" : res;
    }
    void mysort(vector<string>& vec, int l, int r){
        if(l >= r)  return;
        int mid = (l + r) >> 1;
        mysort(vec, l, mid);
        mysort(vec, mid + 1, r);
        for(int i = l; i <= r; i++){
            tmp[i] = vec[i];
        }
        int li = l, ri = mid + 1;
        while(li <= mid || ri <= r){
            if(li > mid){
                vec[l] = tmp[ri];
                ri++;
            }else if(ri > r){
                vec[l] = tmp[li];
                li++;
            }else if(cmp(tmp[li], tmp[ri])){
                vec[l] = tmp[li];
                li++;
            }else{
                vec[l] = tmp[ri];
                ri++;
            }
            l++;
        }
    }
    static bool cmp(const string& a, const string& b){
        return a + b > b + a;
    }
};