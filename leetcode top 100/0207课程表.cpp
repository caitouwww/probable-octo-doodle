class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,set<int>> adjcent;
        vector<int> indegree(numCourses);
        for(auto&edge:prerequisites){
            int a = edge[0], b = edge[1];
            adjcent[b].insert(a);
            indegree[a]++;
        }
        int count = 0;
        queue<int> q;
        for(int i = 0; i < numCourses; ++i){
            if(!indegree[i])q.push(i);
        }
        while(!q.empty()){
            auto v = q.front();
            q.pop();
            ++count;
            auto& adjs = adjcent[v];
            for(auto adj:adjs){
                --indegree[adj];
                if(!indegree[adj])q.push(adj);
            }
        }
        return count==numCourses;
    }
};
