class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        /*priority_queue<int> pq;
        for(auto x:stones) pq.push(x);
        while(pq.size()>=2){
            int top1=pq.top();pq.pop();
            int top2=pq.top();pq.pop();
            int tmp=abs(top1-top2);
            if(tmp) pq.push(tmp);
        }
        return pq.size()==1?pq.top():0;*/
        int size=stones.size();
        for(int i=0;i<size-1;i++)
        {
            sort(stones.begin(),stones.end());
            int weight=stones[size-1]-stones[size-2];
            stones[size-2]=0;
            stones[size-1]=weight;
        }
        return stones[size-1];
    }
};