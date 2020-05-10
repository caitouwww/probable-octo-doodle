class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int size = numbers.size();
        if(size == 0)    return 0;
        sort(numbers.begin(), numbers.end());
        int mid = (size - 1) / 2;
        int l = mid - 1, r = mid + 1;
        int cnt = 1, num = numbers[mid];
        while(l >= 0 && numbers[l--] == num)    cnt++;
        while(r <= size - 1 && numbers[r++] == num)    cnt++;
        if(cnt > size / 2)    return num;
        else    return 0;
    }
};