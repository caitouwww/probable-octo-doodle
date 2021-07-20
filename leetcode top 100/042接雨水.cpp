class Solution {
public:
    int trap(vector<int>& height) {
        //暴力
        // int n = height.size();
        // int ans = 0;
        // for(int i = 1; i < n-1; ++i){
        //     int leftMax = 0, rightMax = 0;
        //     for(int j = i; j >=0; --j){
        //         leftMax = max(leftMax,height[j]);
        //     }
        //     for(int j = i; j < n; ++j){
        //         rightMax = max(rightMax,height[j]);
        //     }
        //     ans+=min(leftMax,rightMax)-height[i];
        // }
        // return ans;
        //备忘录优化
        // if(height.empty())return 0;
        // int n = height.size();
        // vector<int> leftMax(n,0),rightMax(n,0);
        // leftMax[0]=height[0];
        // rightMax[n-1]=height[n-1];
        // for(int i = 1; i < n; ++i)leftMax[i] = max(height[i],leftMax[i-1]);
        // for(int i = n-2;i>=0;--i)rightMax[i] = max(height[i],rightMax[i+1]);
        // int ans = 0;
        // for(int i = 0; i < n; ++i){
        //     ans+=min(leftMax[i],rightMax[i])-height[i];
        // }
        // return ans;
        //双指针
        int n = height.size();
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;
        while(left<right){
            leftMax = max(leftMax,height[left]);
            rightMax = max(rightMax,height[right]);
            if(leftMax<rightMax){
                ans+=leftMax-height[left];
                left++;
            }else{
                ans+=rightMax-height[right];
                right--;
            }
        }
        return ans;
    }
};
