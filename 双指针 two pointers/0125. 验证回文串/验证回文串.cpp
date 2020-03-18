class Solution {
public:
    /*bool charIsValid(char c)
    {
        return isdigit(c)||isalpha(c);
    }
    bool isSameType(char a,char b)
    {
        if((isalpha(a))&&(isalpha(b)))
            return true;
        if((isdigit(a))&&(isdigit(b)))
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        int left=0,right=s.size()-1;
        while(left<=right)
        {
            if(charIsValid(s[left])&&(charIsValid(s[right])))
            {
                if(isSameType(s[left],s[right]))
                {
                    if(s[left]==s[right])
                    {
                        left++;
                        right--;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(!charIsValid(s[left]))
                    left++;
                if(!charIsValid(s[right]))
                    right--;
            }
        } 
        return true;
    }*/
    bool isPalindrome(string s)
    {
        if(s.size()<=1)
            return true;
        int i=0,j=s.size()-1;
        while(i<j)
        {
            while(i<j&&(!isalnum(s[i])))
                i++;
            while(i<j&&(!isalnum(s[j])))
                j--;
            if(tolower(s[i++])!=tolower(s[j--]))
                return false;
        }
        return true;
    }
    
};