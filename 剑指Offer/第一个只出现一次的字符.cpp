class Solution {
public:
    int FirstNotRepeatingChar(string s) {
        int size = s.size();
        if(size == 0)   return -1;
        vector<bool> flag(size, false);
        int i = 0;
        int cnt = 0;
        while(i < size){
            if(flag[i] == true) i++;
            else{
                int j = i;
                while(j < size){
                    if(flag[j] == true) j++;
                    else{
                        if(s[j] == s[i]){
                            cnt++;
                            flag[j] = true;
                        }
                        j++;
                    }
                }
                if(cnt == 1)    return i;
                else    cnt = 0;
                i++;
            }
        }
        return -1;
    }
};
