class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        /*for(int n:nums)
        {
            pq.push(n);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        K = k;*/
        for(int n:nums)
        {
            st.insert(n);
            if(st.size()>k)
            {
                st.erase(st.begin());
            }
        }
        K=k;
    }
    
    int add(int val) {
        /*pq.push(val);
        if(pq.size()>K)
        {
            pq.pop();
        }
        return pq.top();*/
        st.insert(val);
        if(st.size()>K)
        {
            st.erase(st.begin());
        }
        return *st.begin();
    }
private:
int K;
//priority_queue<int,vector<int>,greater<int>> pq;
multiset<int> st;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */