class Solution {
public:
    int numTrees(int n) {
        if(n<=2)return n;
        vector<int> f(n+1);
        f[0] = 1;
        f[1] = 1;
        f[2] = 2;
        for(int i = 3; i <= n; ++i){
            for(int j = 0,k=i-1;j<=n-1,k>=0;++j,--k){
                f[i]+=f[j]*f[k];
            }
        }
        return f[n];
    }
};
