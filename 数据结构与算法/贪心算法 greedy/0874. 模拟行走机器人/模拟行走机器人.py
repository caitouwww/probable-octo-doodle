"""
��������һ�����޴�С�����������ߣ��ӵ�?(0, 0) ����ʼ���������򱱷����û����˿��Խ��������������͵����

-2������ת90��
-1������ת90��
1 <= x <= 9����ǰ�ƶ�x����λ����
����������һЩ���ӱ���Ϊ�ϰ��

�� i���ϰ���λ������� (obstacles[i][0], obstacles[i][1])

�����������ͼ�ߵ��ϰ����Ϸ�����ô����ͣ�����ϰ����ǰһ�����񷽿��ϣ�����Ȼ���Լ�����·�ߵ����ಿ�֡�

���ش�ԭ�㵽�����˵����ŷʽ�����ƽ����



ʾ�� 1��

����: commands = [4,-1,3], obstacles = []
���: 25
����: �����˽��ᵽ�� (3, 4)
ʾ��2��

����: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
���: 65
����: ����������ת�ߵ� (1, 8) ֮ǰ�������� (1, 4) ��


��ʾ��

0 <= commands.length <= 10000
0 <= obstacles.length <= 10000
-30000 <= obstacle[i][0] <= 30000
-30000 <= obstacle[i][1] <= 30000
�𰸱�֤С��2 ^ 31

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/walking-robot-simulation
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        dx = [0,1,0,-1]
        dy = [1,0,-1,0]
        x = y = di = 0
        obstacleSet = set(map(tuple, obstacles))
        ans = 0
        for cmd in commands:
            if cmd == -2:
                di = (di-1)%4
            elif cmd == -1:
                di = (di+1)%4
            else:
                for k in range(cmd):
                    if (x+dx[di],y+dy[di]) not in obstacleSet:
                        x = x + dx[di]
                        y = y + dy[di]
                        ans = max(ans, x*x+y*y)
                    else:
                        break
        return ans