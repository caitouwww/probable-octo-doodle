class Solution {
public:
    void reOrderArray(vector<int> &array) {
        //��д
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
 * 1.Ҫ�뱣֤ԭ�д�����ֻ��˳���ƶ������ڽ�����
 * 2.i�������ұ������ҵ���һ��ż����
 * 3.j��i+1��ʼ����ң�ֱ���ҵ���һ��������
 * 4.��[i,...,j-1]��Ԫ���������һλ������ҵ�����������iλ�ã�Ȼ��i++��
 * 5.�Kֹ�l����j�����v����ʧ����
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