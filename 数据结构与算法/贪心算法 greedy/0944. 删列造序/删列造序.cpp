class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int vectorSize=A.size();
        int stringSize=A[0].size();
        int res=0;
        for(int i=0;i<stringSize;i++)
        {
            char maxChr=A[0][i];
            for(int j=1;j<vectorSize;j++)
            {
                /*if(A[j][i]>maxChr)  maxChr=A[j][i];
                else if(A[j][i]<maxChr) 
                {
                    res++;
                    break;
                }*/
                if(A[j][i]<A[j-1][i])
                {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};