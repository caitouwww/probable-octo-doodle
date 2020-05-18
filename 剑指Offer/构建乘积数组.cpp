class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int size = A.size();
        vector<int> res(size);
        for(int i = 0, p = 1; i < size; p *= A[i], i++){
            res[i] = p;
        }
        for(int i = size - 1, p = 1; i >= 0; p *= A[i], i--){
            res[i] *= p;
        }
        return res;
    }
};