class Solution {
public:
    void replaceSpace(char *str,int length) {
        //运行时间：5ms
        //占用内存：604k
        /*int backspace = 0;
        for(int i = 0; i < length; i++){
            if(*(str + i) == ' ')    backspace++;
        }
        int l = length - 1;
        length += backspace * 2;
        for(char *p = (str +l); l >= 0; p--, l--){
            if(*p == ' '){
                *(p + (backspace - 1) * 2) = '%';
                *(p + (backspace - 1) * 2 + 1) = '2';
                *(p + (backspace - 1) * 2 + 2) = '0';
                backspace--;
            }
            else{
                *(p + backspace * 2) = *p;
            }
        }*/
        //length为字符数组的总容量，上面的代码没弄清楚length的意思
        if(str == nullptr || length <= 0)    return;
        int originalLength = 0;
        int numberOfBlank = 0;
        int i = 0;
        while(str[i] != '\0'){
            ++originalLength;
            if(str[i] == ' ')    ++numberOfBlank;
            ++i;
        }
        int newLength = originalLength + numberOfBlank * 2;
        if(newLength > length)    return;
        int indexOfOriginal = originalLength;
        int indexOfNew = newLength;
        while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal){
            if(str[indexOfOriginal] == ' '){
                str[indexOfNew--] = '0';
                str[indexOfNew--] = '2';
                str[indexOfNew--] = '%';
            }
            else{
                str[indexOfNew--] = str[indexOfOriginal];
            }
            --indexOfOriginal;
        }
    }
};