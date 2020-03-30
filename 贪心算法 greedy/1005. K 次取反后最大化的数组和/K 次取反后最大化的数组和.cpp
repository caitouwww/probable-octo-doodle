class Solution {
public:
    // int smallest(vector<int>& A)
    // {
    //     int val=A[0];
    //     int index=0;
    //     for(int i=1;i<A.size();i++){
    //         if(A[i]<val){
    //             index=i;
    //             val=A[i];
    //         }
    //     }
    //     return index;
    // }
    int largestSumAfterKNegations(vector<int>& A, int K) {
    //    if(K==0) return accumulate(A.begin(),A.end(),0);
    //    else{
    //        int res=smallest(A);
    //        A[res]=-A[res];
    //        return largestSumAfterKNegations(A,K-1);
    //    } 
    int arr[201]={0};
    for(int t:A)
    {
        arr[100+t]++;
    }
    int i=0;
    while (K>0)
    {
        while(arr[i]==0)    i++;
        arr[i]--;
        arr[200-i]++;
        if(i>100)
        {
            i=200-i;
        }
        K--;
    }
    int sum=0;
    for(int j=i;j<201;j++)
    {
        sum+=(j-100)*arr[j];
    }
    return sum;
    }
};