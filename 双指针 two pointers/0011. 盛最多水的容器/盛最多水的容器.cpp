class Solution {
public:
    int maxArea(vector<int>& height) {
        //��ʱ
        // int res=0;
        // for(int i=0;i<height.size()-1;i++)
        // {
        //     for(int j=i+1;j<height.size();j++)
        //     {
        //         int area=min(height[i],height[j])*(j-i);
        //         if(area>res) res=area;
        //     }
        // }
        // return res;
        
        // ���������Ž⣬��Ϊһ��ʼ����ָ��һ��ָ�����һ��ָ���Ҳ࣬
        // ���һ�����������ƶ����õ��Ľ���϶���֮ǰ��С����ָ�����С����min(����height)ֻ��С�򲻱䵫�϶�����󡿣�
        // ����С��һ�������ƶ��������Сδ֪��������������࿴һ����������һ��height��С���ֱ��������
        if(height.size()<=1)    return -1;
        int i=0,j=height.size()-1,res=0;
        while(i<j)
        {
            int h=min(height[i],height[j]);
            res=max(res,h*(j-i));
            if(height[i]<height[j]) i++;
            else j--;
        }
        return res;
    }
};