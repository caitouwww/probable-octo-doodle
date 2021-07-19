class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int len = m + n;
        int a = 0, b = 0;
        int left = 0, right = 0;
        for(int i = 0; i <= len/2; ++i){
            left = right;
            if(a<m&&(b>=n||nums1[a]<=nums2[b])){
                right = nums1[a++];
            }else{
                right = nums2[b++];
            }
        }
        if(len&1==1)return right;
        else return 1.0*(left+right)/2;
    }
};
