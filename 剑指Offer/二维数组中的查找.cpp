class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        //����
        /*
        if(array.size() == 0)    return false;
        int row = array.size();
        int column = array[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                if(array[i][j] == target)    return true;
            }
        }
        return false;
        */
        /*if(array.size() == 0)    return false;
        int row = 0, col = array[0].size() - 1;
        while(row < array.size() && col >= 0){
            if(array[row][col] < target)    row++;
            else if(array[row][col] > target)    col--;
            else return true;
        }
        return false;*/
        //���ֲ��ң������У���leetcode74��ͬ
        /*this q    leetcode74
        //1 2 3 4    1 2 3 4
        //2 3 4 5    5 6 7 8
        //3 4 5 6    9 10 11 12
        //���Բ�ȡ���ֶ��ֲ���
        */
        int size = array.size();
        if(size == 0)    return false;
        if(size == 1){
            if(array[0].size() == 0)    return false;
        }
        int row = size;
        int column = array[0].size() - 1;
        for(int i = 0; i < row; i++){
            if(BS(array, target, i, 0, column))    return true;
        }
        return false;
    }
    bool BS(vector<vector<int> >& arr, int tar, int row, int s, int e){
        while(s < e){
            int m = s + (e - s + 1) / 2;
            if(arr[row][m] <= tar)    s = m;
            else    e = m - 1;
        }
        if(arr[row][s] == tar)    return true;
        else return false;
    }
};