class Solution {
public:
    //¶þ·Ö
    // bool search_column(vector<vector<int>>& matrix, int row, int left, int right, int target)
    // {
    //     if(row==-1) return false;
    //     while(left<right)
    //     {
    //         int mid=left+(right-left)/2;
    //         if(matrix[row][mid]<=target)    left=mid;
    //         else right=mid-1;
    //     }
    //     if(matrix[row][left]==target)   return true;
    //     else return false;
    // }
    // int get_row(vector<vector<int>>& matrix, int column, int left, int right, int target)
    // {
    //     while(left<right)
    //     {
    //         int mid=left+(right-left)/2;
    //         if(matrix[mid][column]<target) left=mid+1;
    //         else right=mid; 
    //     }
    //     if(matrix[left][column]>=target)    return left;
    //     else return -1;
    // }
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     if(matrix.size()==0)  return false;
    //     int row=get_row(matrix,matrix[0].size()-1,0,matrix.size()-1,target);
    //     return search_column(matrix,row,0,matrix[0].size()-1,target);
    // }
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if(matrix.size()==0)    return false;
        int row=0,column=matrix[0].size()-1;
        while(row<matrix.size()&&column>=0)
        {
            if(matrix[row][column]<target)
                row++;
            else if(matrix[row][column]>target)
                column--;
            else
                return true;
        }
        return false;
    }
};