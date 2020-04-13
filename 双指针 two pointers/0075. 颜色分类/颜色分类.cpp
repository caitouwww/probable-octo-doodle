class Solution {
public:
    void sortColors(vector<int>& nums) {
        //按照进阶提示所写
        // int zero=0,one=0,two=0;
        // int size=nums.size();
        // for(int i=0;i<size;i++)
        // {
        //     if(nums[i]==0)  zero++;
        //     else if(nums[i]==1) one++;
        //     else two++;
        // }
        // for(int i=0;i<size;i++)
        // {
        //     if((zero--)>0)    nums[i]=0;
        //     else if((one--)>0)    nums[i]=1;
        //     else nums[i]=2;
        // }
        //使用库函数
        // vector<int> c(3,0);
        // for(int i=0;i<nums.size();i++)
        // {
        //     c[nums[i]]++;
        // }
        // fill(nums.begin(),nums.begin()+c[0],0);
        // fill(nums.begin()+c[0],nums.begin()+c[0]+c[1],1);
        // fill(nums.begin()+c[0]+c[1],nums.end(),2);
        // 0，1，2 排序。一次遍历，如果是0，则移动到表头，如果是2，则移动到表尾，不用考虑1。0和2处理完，1还会有错吗？
        int size=nums.size();
        int front=0,last=size-1;
        int cur=0;
        while(cur<=last)
        {
            if(nums[cur]==0)  swap(nums[cur++],nums[front++]);
            else if(nums[cur]==2) swap(nums[cur],nums[last--]);
            else    cur++;
        }
    }
};