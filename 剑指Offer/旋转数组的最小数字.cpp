class Solution {
public:
    int minNumberInRotateArray(vector<int> rA) {
        //һ��ⷨ
        /*int size = rotateArray.size();
        for(int i = 1; i < size; i++){
            if(rotateArray[i] < rotateArray[i - 1])    return rotateArray[i];
        }
        return 0;*/
        //���ֽⷨ
        if(rA.size() == 0)    return 0;
        int l = 0, r = rA.size() - 1;
        int mid = l;
        while(rA[l] >= rA[r]){
            if(r - l == 1){
                mid = r;
                break;
            }
            mid = (l + r) / 2;
            //����±�Ϊl, mid, r����������ͬ�������ж���С����ǰ�滹�Ǻ�����������ֻ��˳�����
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