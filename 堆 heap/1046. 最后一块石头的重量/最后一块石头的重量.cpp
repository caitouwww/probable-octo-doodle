class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        /*for(int x:stones)
        {
            st.insert(x);
        }
        while(st.size()>1)
        {
            int y=*st.begin();
            st.erase(st.begin());
            int x=*st.begin();
            st.erase(st.begin());
            if(y-x!=0)
                st.insert(y-x);
        }
        if(st.size()==1)
            return *st.begin();
        else
        {
            return 0;
        }*/
        
        for(int x:stones)
        {
            pq.push(x);
        }
        while(pq.size()>1)
        {
            int y=pq.top();
            pq.pop();
            int x= pq.top();
            pq.pop();
            if(y-x!=0)
            {
                pq.push(y-x);
            }        
        }
        if(pq.size()==1)
        {
            return pq.top();
        }
        else
        {
            return 0;
        }
        
    }
private:
//multiset<int,greater<int>> st;
priority_queue<int,vector<int>,less<int>> pq;
};