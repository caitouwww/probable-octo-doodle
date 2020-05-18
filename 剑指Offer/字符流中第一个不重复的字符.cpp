class Solution
{
public:
    Solution():index(0) {
        for(int i = 0; i < 256; i++){
            occurrence[i] = -1;
        }
    }
  //Insert one char from stringstream
    void Insert(char ch)
    {
         if(occurrence[ch] == -1)    occurrence[ch] = index;
        else if(occurrence[ch] >= 0)    occurrence[ch] = -2;
        
        index++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        char ch = '#';
        int minIndex = numeric_limits<int>::max();
        for(int i = 0; i < 256; i++){
            if(occurrence[i] >= 0 && occurrence[i] < minIndex){
                minIndex = occurrence[i];
                ch = (char)i;
                //break;
            }
        }
        return ch;
    }
private:
    //occurrence[i]: A character with ascii value i;
    //occurrence[i] = -1: The character has not found;
    //occurrence[i] = -2 : The character has been found multiple times;
    //occurrence[i] >= 0: The character has been found only once.
    char occurrence[256];
    int index;
};