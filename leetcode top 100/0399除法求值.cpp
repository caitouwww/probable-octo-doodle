class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int nvars = 0;
        unordered_map<string,int> variables;
        int n = equations.size();
        for(int i = 0; i < n; ++i){
            if(variables.find(equations[i][0])==variables.end()){
                variables[equations[i][0]] = nvars++;
            }
            if(variables.find(equations[i][1])==variables.end()){
                variables[equations[i][1]] = nvars++;
            }
        }
        vector<vector<pair<int,double>>> edges(nvars);
        for(int i = 0; i < n; ++i){
            int va = variables[equations[i][0]], vb = variables[equations[i][1]];
            edges[va].push_back(make_pair(vb,values[i]));
            edges[vb].push_back(make_pair(va,1.0/values[i]));
        }

        vector<double> res;
        for(const auto&q:queries){
            double result = -1.0;
            if(variables.find(q[0])!=variables.end()&&variables.find(q[1])!=variables.end()){
                int ia = variables[q[0]], ib = variables[q[1]];
                if(ia==ib)result = 1.0;
                else{
                    queue<int> q;
                    q.push(ia);
                    vector<double> ratios(nvars,-1.0);
                    ratios[ia] = 1.0;
                    while(!q.empty()&&ratios[ib]<0){
                        int x = q.front();
                        q.pop();
                        for(const auto [y,val]:edges[x]){
                            if(ratios[y]<0){
                                ratios[y] = ratios[x]*val;
                                q.push(y);
                            }
                        }
                    }
                    result = ratios[ib];
                }
            }
            res.push_back(result);
        }
        return res;
    }
};
