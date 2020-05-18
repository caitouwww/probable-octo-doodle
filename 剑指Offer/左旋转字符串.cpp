class Solution {
public:
    string LeftRotateString(string str, int n) {
        int size = str.size();
        string res;
        if(size == 0)    return res;
        n = n % size;
        for(int i = n; i < size; i++)    res += str[i];
        for(int i = 0; i < n; i++)    res += str[i];
        return res;
    }
};