class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        /*vector<string> res;
        string tmp="00:00";
        string tmp1="0:00";
        for(int i=0;i<12;i++)
        {
            bitset<4> b=i;
            int num1=b.count();
            for(int j=0;j<60;j++)
            {
                bitset<6> s=j;
                int num2=s.count();
                if(num1+num2==num)
                {
                    if(i<10)
                    {
                        tmp1[0]=i-1+'1';
                        if(j<10)
                        {
                            tmp1[2]='0';
                            tmp1[3]=j-1+'1';
                        }
                        else
                        {
                            tmp1[2]=j/10-1+'1';
                            tmp1[3]=j%10-1+'1';
                        }
                        res.push_back(tmp1);
                    }
                    else
                    {
                        tmp[0]=i/10-1+'1';
                        tmp[1]=i%10-1+'1';
                        if(j<10)
                        {
                            tmp[3]='0';
                            tmp[4]=j-1+'1';
                        }
                        else
                        {
                            tmp[3]=j/10-1+'1';
                            tmp[4]=j%10-1+'1';
                        }
                        res.push_back(tmp);
                    }
                }
            }
        }
        return res;*/
        vector<string> res;
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<60;j++)
            {
                if(count1(i)+count1(j)==num)
                {
                    res.push_back(to_string(i)+":"+(j<10?"0"+to_string(j):to_string(j)));
                }
            }
        }
        return res;
    }
    int count1(int i)
    {
        int cnt=0;
        while(i)
        {
            cnt++;
            i=i&(i-1);
        }
        return cnt;
    }
};