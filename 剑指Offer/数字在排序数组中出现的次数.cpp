class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int idx = binarySearchFirstApper(data, k, 0, data.size() - 1);
        int res = 0;
        if(idx == -1)    return 0;
        while(idx < data.size()){
            if(data[idx++] == k)    res++;
            else    break;
        }
        return res;
    }
    int binarySearchFirstApper(vector<int>& data, int k, int l, int r){
        if(l > r)    return -1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(data[mid] < k)    l = mid + 1;
            else if(data[mid] > k)    r = mid - 1;
            else r = mid;
        }
        if(data[l] == k)    return l;
        else return -1;
    }
};