class Solution {
public:
    bool match(char* s, char* p)
    {
        if(*p == '\0')    return *s == '\0';
        else{
            if(*(p + 1) == '*')
                return match(s, p + 2) || (*s != '\0' && (*s == *p || *p == '.')) && match(s + 1, p);
            else
                return (*s != '\0' && (*s == *p || *p == '.')) && match(s + 1, p + 1);
        }
    }
};