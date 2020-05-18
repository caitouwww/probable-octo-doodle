class Solution {
public:
    void Insert(int num)
    {
        if(((minHeap.size() + maxHeap.size()) & 1) == 0){
            if(maxHeap.size() > 0 && num < maxHeap[0]){
                maxHeap.push_back(num);
                push_heap(maxHeap.begin(), maxHeap.end(), less<int>());
                
                num = maxHeap[0];
                pop_heap(maxHeap.begin(), maxHeap.end(), less<int>());
                maxHeap.pop_back();
            }
            minHeap.push_back(num);
            push_heap(minHeap.begin(), minHeap.end(), greater<int>());
        }else{
            if(minHeap.size() > 0 && num > minHeap[0]){
                minHeap.push_back(num);
                push_heap(minHeap.begin(), minHeap.end(), greater<int>());
                
                num = minHeap[0];
                pop_heap(minHeap.begin(), minHeap.end(), greater<int>());
                minHeap.pop_back();
            }
            maxHeap.push_back(num);
            push_heap(maxHeap.begin(), maxHeap.end(), less<int>());
        }
    }

    double GetMedian()
    { 
        int size = minHeap.size() + maxHeap.size();
        if(size == 0)    return 0;
        double median = 0;
        if((size & 1) == 1)    median =  minHeap[0];
        else    median =  (minHeap[0] + maxHeap[0]) / 2.0;
        return median;
    }
private:
    vector<int> minHeap;
    vector<int> maxHeap;
};