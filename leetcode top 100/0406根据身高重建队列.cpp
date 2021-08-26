// class Solution {
// public:
//     vector<vector<int>> res;
//     vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//         int m = people.size();
//         vector<bool> used(m,false);
//         vector<vector<int>> cur;
//         backtrack(people,used,cur,0);
//         return res;
//     }
//     void backtrack(vector<vector<int>>& people, vector<bool>& used, vector<vector<int>>& cur, int index){
//         if(index==people.size()){
//             res = cur;
//             return;
//         }
//         for(int i = 0; i < people.size(); ++i){
//             if(!used[i]){
//                 int cnt = 0;
//                 int h = people[i][0], k = people[i][1];
//                 for(int i = 0; i < cur.size(); ++i){
//                     int hj = cur[i][0];
//                     if(hj>=h)cnt++;
//                 }
//                 if(cnt==k){
//                     cur.push_back(people[i]);
//                     used[i] = true;
//                     backtrack(people,used,cur,index+1);
//                     cur.pop_back();
//                     used[i] = false;
//                 }
//             }
//         }
        
//     }
// };
// https://leetcode-cn.com/problems/queue-reconstruction-by-height/solution/406-gen-ju-shen-gao-zhong-jian-dui-lie-pai-xu-hou-/
struct cmp{
    bool operator()(vector<int>& a, vector<int>& b){
        if(a[0]==b[0])return a[1]<b[1];
        else return a[0]>b[0];
    }
};
class Solution{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people){
        sort(people.begin(),people.end(),cmp());
        vector<vector<int>> ans;
        for(auto&p:people){
            ans.insert(ans.begin()+p[1],p);
        }
        return ans;
    }
};
