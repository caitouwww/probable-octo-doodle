class Solution {
public:
    int maxArea(vector<int>& height) {
        //超时
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
        
        // 不会错过最优解，因为一开始两个指针一个指向左侧一个指向右侧，
        // 大的一方假如向内移动所得到的结果肯定比之前的小【两指针间距变小，且min(两个height)只变小或不变但肯定不变大】，
        // 但是小的一方向内移动结果变大变小未知。【假如能往里多看一步，发现下一个height更小则可直接跳过】
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