class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        int x=0;
        int y=0;
        int di=0;
        int ans=0;
        set<pair<int,int>> obsSet;
        for(vector<int> obs:obstacles)
        {
            obsSet.insert(make_pair(obs[0],obs[1]));
        }
        for(int cmd:commands)
        {
            if(cmd==-2)
                di=(di+3)%4;
            else if(cmd==-1)
                di=(di+1)%4;
            else
            {
                for(int i=0;i<cmd;i++)
                {
                    int tmpx=x+dx[di];
                    int tmpy=y+dy[di];
                    if(obsSet.find(make_pair(tmpx,tmpy))==obsSet.end())
                    {
                        x=tmpx;
                        y=tmpy;
                        ans=max(ans,x*x+y*y);
                    }
                }
            }
        }
        return ans;
        /*int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        //ÿ������ǰ��ʱ����������
        int x = 0, y = 0;//�����˵�����
        int di = 0;//���� ��0 ��1 ��2 ��3

        set<pair<int,int>> obstacleSet;//����ϰ���ļ���
        for (vector<int> obstacle: obstacles)
            obstacleSet.insert(make_pair(obstacle[0], obstacle[1]));

        int ans = 0;//���ŷʽ����
        for (int cmd: commands) {
            if (cmd == -2)
                di = (di + 3) % 4;
            else if (cmd == -1)
                di = (di + 1) % 4;
            else {
                for (int k = 0; k < cmd; ++k) {
                    int nx = x + dx[di];
                    int ny = y + dy[di];
                    if (obstacleSet.find(make_pair(nx, ny)) == obstacleSet.end()) {
                        x = nx;
                        y = ny;
                        ans = max(ans, x*x + y*y);
                    }
                }
            }
        }
        return ans;*/
    }
};