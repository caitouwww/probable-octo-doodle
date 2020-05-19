class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //分治法
        //return maxSubArrayDivideWithBorder(nums,0,nums.size()-1);
        //暴力法
        /*int res=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=0;
            for(int j=i;j<nums.size();j++)
            {
                sum+=nums[j];
                res=max(sum,res);
            }
        }
        return res;*/
        //动态规划
        /*vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        int wholemax=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            dp[i]=max(dp[i-1],0)+nums[i];
            wholemax=max(wholemax,dp[i]);
        }
        return wholemax;*/
        //贪心算法
        int wholemax=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            wholemax=max(wholemax,sum);
            if(sum<0)
                sum=0;
        }
        return wholemax;

    }
    /*int maxSubArrayDivideWithBorder(vector<int>& nums,int start,int end)
    {
        if(start==end)
            return nums[start];
        int center=(start+end)/2;
        int leftMax=maxSubArrayDivideWithBorder(nums,start,center);
        int rightMax=maxSubArrayDivideWithBorder(nums,center+1,end);

        int leftCrossMax=INT_MIN;
        int leftCrossSum=0;
        for(int i=center;i>=start;i--)
        {
            leftCrossSum+=nums[i];
            leftCrossMax=max(leftCrossMax,leftCrossSum);
        }

        int rightCrossMax=INT_MIN;
        int rightCrossSum=0;
        for(int i=center+1;i<=end;i++)
        {
            rightCrossSum+=nums[i];
            rightCrossMax=max(rightCrossMax,rightCrossSum);
        }

        int crossMax=leftCrossMax+rightCrossMax;
        return max(max(leftMax,rightMax),crossMax);
    }*/
};