class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //×ÔÐ´
        // sort(nums.begin(),nums.end());
        // int res=INT32_MAX;
        // int flag=0;
        // for(int i=0;i<nums.size()-2;i++)
        // {
        //     int p=nums[i];
        //     int l=i+1,r=nums.size()-1;
        //     while(l<r)
        //     {
        //         if(p+nums[l]+nums[r]<target) 
        //         {
        //             if(abs(p+nums[l]+nums[r]-target)<res)
        //             {
        //                 res=abs(p+nums[l]+nums[r]-target);
        //                 flag=-1;
        //             }
        //             l++;
        //         }
        //         else if(p+nums[l]+nums[r]>target)   
        //         {
        //             if(abs(p+nums[l]+nums[r]-target)<res)
        //             {
        //                 res=abs(p+nums[l]+nums[r]-target);
        //                 flag=1;
        //             }
        //             r--;
        //         }
        //         else    return target;
        //     }
        // }
        // if(flag==1) return res+target;
        // else if(flag==-1)   return -res+target;
        // else return 0;
        //ÅÅÐò£¬±éÀú£¬Ë«Ö¸Õë
        sort(nums.begin(),nums.end());
        int closestNum=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size()-2;i++)
        {
            int l=i+1,r=nums.size()-1;
            while(l<r)
            {
                int threeSum=nums[i]+nums[l]+nums[r];
                if(abs(threeSum-target)<abs(closestNum-target))
                {
                    closestNum=threeSum;
                }
                if(threeSum>target)
                    r--;
                else if(threeSum<target)
                    l++;
                else
                    return target;
            }
        }
        return closestNum;
    }
};