#define N 10010
class Solution
{   
    int bit[N];
    public:
    // int get(int x)
    // {
    //     int res=0;
    //     while(x)
    //     {
    //         res+=x&1;
    //         x>>=1;
    //     }
    //     return res;
    // }
    vector<int> sortByBits(vector<int>& arr)
    {
        // sort(arr.begin(),arr.end());
        // map<int,vector<int>> res;
        // for(int val:arr)
        // {
        //     res[count1(val)].push_back(val);
        // }
        // vector<int> vres;
        // for(auto iter=res.begin();iter!=res.end();iter++)
        // {
        //     for(auto i:iter->second)
        //     {
        //         vres.push_back(i);
        //     }
        // }
        // return vres;
        //暴力
        // for(auto x:arr) bit[x]=get(x);
        // sort(arr.begin(),arr.end(),[&](int x,int y){//改写排序规则
        //     return bit[x]==bit[y]?x<y:bit[x]<bit[y];
        // });
        // return arr;
        //递推预处理
        // for(int i=0;i<=10000;i++) bit[i]=bit[i>>1]+(i&1);
        // sort(arr.begin(),arr.end(),[&](int x,int y){//[&] 用到的任何外部变量都隐式按引用捕获
        //     return bit[x]==bit[y]?x<y:bit[x]<bit[y];
        // });
        // return arr;
        //系统库函数，统计x在二进制下的数字1的个数，内部实现是用查找表实现的
        for(auto x:arr) bit[x]=__builtin_popcount(x);
        sort(arr.begin(),arr.end(),[&](int x,int y){
            return bit[x]==bit[y]?x<y:bit[x]<bit[y];
        });
        return arr;
    }
    // int count1(int num)
    // {
    //     int cnt=0;
    //     while (num)
    //     {
    //         cnt++;
    //         num=num&(num-1);
    //     }
    //     return cnt;
    // }
};