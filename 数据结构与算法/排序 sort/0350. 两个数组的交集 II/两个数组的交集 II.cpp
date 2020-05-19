class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        /*vector<int> res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),insert_iterator<vector<int>> (res,res.begin()));
        return res;*/
        /*sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0,k=0;
        while(i<nums1.size()&&j<nums2.size())
        {
            if(nums1[i]<nums2[j])
                i++;
            else if(nums2[j]<nums1[i])
                j++;
            else
            {
                nums1[k++]=nums1[i++];
                j++;
            }
        }
        return vector<int> (nums1.begin(),nums1.begin()+k);*/
        unordered_map<int,int> m;
        for(auto x:nums1)
        {
            ++m[x];
        }
        int k=0;
        for(auto x:nums2)
        {
            auto a = m.find(x);
            if(a!=m.end()&&a->second>0)
            {
                a->second--;
                nums1[k++]=x;
            }
        }
        return vector<int> (nums1.begin(),nums1.begin()+k);
    }
};