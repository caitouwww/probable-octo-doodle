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
        //����
        // for(auto x:arr) bit[x]=get(x);
        // sort(arr.begin(),arr.end(),[&](int x,int y){//��д�������
        //     return bit[x]==bit[y]?x<y:bit[x]<bit[y];
        // });
        // return arr;
        //����Ԥ����
        // for(int i=0;i<=10000;i++) bit[i]=bit[i>>1]+(i&1);
        // sort(arr.begin(),arr.end(),[&](int x,int y){//[&] �õ����κ��ⲿ��������ʽ�����ò���
        //     return bit[x]==bit[y]?x<y:bit[x]<bit[y];
        // });
        // return arr;
        //ϵͳ�⺯����ͳ��x�ڶ������µ�����1�ĸ������ڲ�ʵ�����ò��ұ�ʵ�ֵ�
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