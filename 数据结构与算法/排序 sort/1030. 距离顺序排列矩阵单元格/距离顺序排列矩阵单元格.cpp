class Solution {
public:
    /*static bool ismax(vector<int>& a,vector<int>& b)
    {
        return a[2]<b[2];
    }*/
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res(R*C,vector<int>(3));
        int num=0;
        for(int i=0;i<C;i++)
        {
            for(int j=0;j<R;j++)
            {
                res[num][0]=j;
                res[num][1]=i;
                res[num][2]=abs(j-r0)+abs(i-c0);
                num++;
            }
        }
        //sort(res.begin(),res.end(),ismax);
        sort(res.begin(),res.end(),[&](vector<int>&a,vector<int>&b){
            return a[2]<b[2];
        });
        for(int i=0;i<num;i++)
        {
            res[i].pop_back();
        }
        return res;
    }
};