class Solution {
public:
    int minNumberInRotateArray(vector<int> rA) {
        //一般解法
        /*int size = rotateArray.size();
        for(int i = 1; i < size; i++){
            if(rotateArray[i] < rotateArray[i - 1])    return rotateArray[i];
        }
        return 0;*/
        //二分解法
        if(rA.size() == 0)    return 0;
        int l = 0, r = rA.size() - 1;
        int mid = l;
        while(rA[l] >= rA[r]){
            if(r - l == 1){
                mid = r;
                break;
            }
            mid = (l + r) / 2;
            //如果下标为l, mid, r的三个数相同，则不能判断最小数在前面还是后面的字数组里，只能顺序查找
            if(rA[l] == rA[mid] && rA[mid] == rA[r])    return minInOrder(rA, l, r);
            if(rA[mid] >= rA[l])    l = mid;
            else if(rA[mid] <= rA[r])    r = mid;
        }
        return rA[mid];
    }
    int minInOrder(vector<int>& rA, int l, int r){
        int res = rA[l];
        for(int i = l + 1; i <= r;i ++){
            if(rA[i] < res)    res = rA[i];
        }
        return res;
    }
};