/*
������Ļ��ݷ���ģ��
��дһ������if-else��dfs(i��n)����
if(i > n) �������
else�а���forѭ����Ŀ������ÿ���ƶ���һ��
for{���ƣ�if������������dfs����ƣ�}
������hour<=11; min<=59; 0~9Сʱ�ı�ʾǰ׺û��0
������0~9���ӵı�ʾǰ׺��0��10~59û��0���á�%.2d���������%02d��Ҳ����
�������������ظ�

for(int pos=0; pos<=9; ++pos)//��������
for(int j=0;j<=9;++j)        //�ҵ���һ�εݹ��е�pos�������ظ�
    if(time[j]==1)
        max=j;
if(pos>max)
*/
class Solution
{
public:
    vector<string> res;
    vector<string> readBinaryWatch(int num)
    {
        vector<int> time(10);
        dfs(0,num,time);
        return res;
    }

    void dfs(int count,int num,vector<int> time)
    {
        if(count>=num)
        {
            int hour=1*time[0]+2*time[1]+4*time[2]+8*time[3];
            int min=1*time[4]+2*time[5]+4*time[6]+8*time[7]+16*time[8]+32*time[9];

            if(hour<=11 && min<=59)
            {
                char buffer[6];
                sprintf(buffer,"%d:%.2d",hour,min);
                                                   //���������ж�buffer��res��Ԫ���Ƿ��ظ����޷����DSƥ������
                res.push_back(buffer);
            }
            return;
        }
        else
        {
            int max=-1;                    //��Ϊ������������䰴�򣬲��ظ�
            for(int j=0;j<=9;++j)
            {
                if(time[j]==1)
                {
                    max=j;
                }
            }
            for(int pos=0; pos<=9; ++pos) 
            {
                time[pos]++;
                if(pos>max)             
                {
                    dfs(count+1,num,time);
                }
                time[pos]--;
            }
        }
    }


};