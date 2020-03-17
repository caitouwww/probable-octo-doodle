class Solution {
public:
    int strStr(string haystack, string needle) {
        /*int sizeh=haystack.size(),sizen=needle.size();
        if(sizen==0)
            return 0;
        if(sizeh<sizen)
            return -1;
        for(int i=0;i<sizeh;i++)
        {
            int k=0;
            if(haystack[i]==needle[0])
            {
                for(int j=0;j<sizen;j++)
                {
                    if(haystack[i+j]==needle[j])
                    {
                        k++;
                        if(k==sizen)
                            return i;
                    }
                    else
                        break;
                }
                if((k!=sizen)&&((i+sizen)==sizeh)) return -1;
            }
        }
        return -1;*/
        //库函数法
        /*if(needle.empty())
            return 0;
        int pos=haystack.find(needle);
        return pos;*/
        //暴力法
        if(needle.empty())
            return 0;
        int i=0,j=0;
        while(haystack[i]!='\0'&&needle[j]!='\0')
        {
            if(haystack[i]==needle[j])
            {
                i++;
                j++;
            }
            else
            {
                i=i-j+1;
                j=0;
            }
        }
        if(needle[j]=='\0')
            return i-j;
        return -1;
    }
};