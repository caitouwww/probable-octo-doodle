class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //方法1
        // vector<pair<int,string>> tmp;
        // int n = strs.size();
        // for(int i = 0; i < n; ++i){
        //     string t = strs[i];
        //     sort(t.begin(),t.end());
        //     tmp.emplace_back(make_pair(i,t));
        // }
        // sort(tmp.begin(),tmp.end(),[](pair<int,string>&a,pair<int,string>&b){
        //     if(a.second==b.second)return a.first<b.first;
        //     return a.second<b.second;
        // });
        // // for(auto&x:tmp)cout << x.first << " " << x.second<<endl;
        // vector<vector<string>> res;
        // int i = 0;
        // while(i<n){
        //     int j = i;
        //     vector<string> r;
        //     while(j<n&&tmp[j].second==tmp[i].second){
        //         r.emplace_back(strs[tmp[j].first]);
        //         j++;
        //     }
        //     res.emplace_back(r);
        //     i = j;
        // }
        // return res;
        //方法2
        // int pr[26] = {2,3,5,7,11,13,17,19,23,29,31,37,41, 43, 47, 53, 59, 61, 67, 71,73,79,83,89,97,101 }; //26个质数
        // unordered_map<double,vector<string> > dics;
        // for(string & str : strs)
        // {
        //     double tmp = 1;
        //     for(char &c : str)
        //     {
        //         tmp *= (pr[c - 'a']);
        //     }
        //     dics[tmp].push_back(str);
        // }
        // vector<vector<string>> ans(dics.size());
        // int k = 0;
        // for(auto k_v : dics)
        // {
        //     ans[k++] = k_v.second;
        // }
        // return ans;
        //方法3
        vector<vector<string>> res;
        map<string, vector<string>> m;
        for(int i = 0; i < strs.size(); i++){
            string key = strs[i];
            sort(key.begin(), key.end());
            m[key].push_back(strs[i]);
        }
        for(auto iter = m.begin(); iter != m.end(); iter++){
            res.push_back(iter->second);
        }
        return res;
    }
};
