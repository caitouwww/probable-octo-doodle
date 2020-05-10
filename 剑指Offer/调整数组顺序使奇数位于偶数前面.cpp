class Solution {
public:
    void reOrderArray(vector<int> &array) {
        //自写
        /*int size = array.size();
        int odd = 0;
        for(int i = 0; i < size; i++){
            if(array[i] % 2 == 1)    odd++;
        }
        vector<int> helper(size, 0);
        int i1 = 0, i2 = odd;
        for(int i = 0; i < size; i++){
            if(array[i] % 2 == 1)    helper[i1++] = array[i];
            else    helper[i2++] = array[i];
        }
        for(int i = 0; i < size; i++){
            array[i] = helper[i];
        }*/
/**
 * 1.要想保证原有次序，则只能顺次移动或相邻交换。
 * 2.i从左向右遍历，找到第一个偶数。
 * 3.j从i+1开始向后找，直到找到第一个奇数。
 * 4.将[i,...,j-1]的元素整体后移一位，最后将找到的奇数放入i位置，然后i++。
 * 5.終止條件：j向後遍歷查找失敗。
 */
        int size = array.size(), i = 0;
        while(i < size){
            while(i < size && !isEven(array[i]))    i++;
            int j = i;
            while(j < size && isEven(array[j]))    j++;
            if(j < size){
                int tmp = array[j];
                for(int j1 = j - 1; j1 >= i; j1--)    array[j1 + 1] = array[j1];
                array[i++] = tmp;
            }else    break;
        }
    }
    bool isEven(int a){
        if(a % 2 == 0)    return true;
        return false;
    }
};