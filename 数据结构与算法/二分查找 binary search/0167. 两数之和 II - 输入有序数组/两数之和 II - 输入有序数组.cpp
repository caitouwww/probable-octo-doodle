class Solution {
public:
    /*bool binarySearch(vector<int>& numbers,int start,int& res,int target)
    {
        int left=start;
        int right=numbers.size()-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(numbers[mid]==target)
            {
                res = mid;
                return true;
            }
            else if(numbers[mid]<target)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return false;
    }*/
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        //³¬Ê±O(n^2)
        /*vector<int> res;
        for(int i=0;i<numbers.size()-1;i++)
        {
            for(int j=i+1;j<numbers.size();j++)
            {
                if(numbers[i]==target-numbers[j])
                {
                    res.push_back(i+1);
                    res.push_back(j+1);
                }
            }
        }
        return res;*/
        //¸´ÔÓ¶ÈO(nlogn)
        /*int j=0;
        vector<int> res;
        for(int i=0;i<numbers.size()-1;i++)
        {
            if(binarySearch(numbers,i+1,j,target-numbers[i]))
            {
                res.push_back(i+1);
                res.push_back(j+1);
            }
        }
        return res;*/
        int l=0;
        int r=numbers.size()-1;
        while(l<r)
        {
            if(numbers[l]==target-numbers[r])
            {
                return {l+1,r+1};
            }
            else if(numbers[l]<target-numbers[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return {-1,-1};
    }
};