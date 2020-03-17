class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(!nums2.empty())
        {
            int j=0;
            for(int i=0;i<m+n;i++)
            {
                if(nums2[j]<nums1[i])
                {
                    nums1.insert(nums1.begin()+i,nums2[j]);
                    j++;
                    if(j==nums2.size())
                        break;
                }
            }
            while(j<nums2.size())
            {
                nums1.insert(nums1.begin()+m+j,nums2[j]);
                j++;
            }
            nums1.resize(m+n);
        }
        
    }
};