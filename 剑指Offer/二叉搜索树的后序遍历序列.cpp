class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())    return false;
        return helper(sequence, 0, sequence.size() - 1);
    }
    bool helper(vector<int>& seq, int start, int end){
        if(start >= end)    return true;
        int s = start;
        for(int i = start; i <= end; i++){
            if(seq[i] < seq[end])    s++;
            else{
                for(int j = s; j <= end; j++){
                    if(seq[j] < seq[end])    return false;
                }
                break;
            }
        }
        return helper(seq, start, s - 1) && helper(seq, s, end - 1);
    }
};