class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        /*for(int i=0;i<A.size()-1;i=i+2)
        {
            if(A[i]%2!=0)
            {
                int j=i;
                while(A[j]%2!=0){j++;}
                swap(A[i],A[j]);
            }
            if(A[i+1]%2==0)
            {
                int j=i+1;
                while(A[j]%2==0){j++;}
                swap(A[i+1],A[j]);
            }
        }
        return A;*/
        int j=1;
        for(int i=0;i<A.size();i=i+2)
        {
            if(A[i]%2==1)
            {
                while(A[j]%2==1)
                    j=j+2;
                swap(A[i],A[j]);
            }
        }
        return A;
    }
};