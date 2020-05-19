class NumArray {
public:
    NumArray(vector<int>& nums) {
        //±©Á¦
        //p_nums=nums;
        //»º´æ
        /*if(nums.size()!=0)
        {
            p_nums.resize(nums.size());
            p_nums[0]=nums[0];
            for(int i=1;i<nums.size();i++)
            {
                p_nums[i]=p_nums[i-1]+nums[i];
            }
        }*/
        p_nums.resize(nums.size()+1);
        for(int i=1;i<nums.size()+1;i++)
        {
            p_nums[i]=p_nums[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        /*int sum=0;
        for(int start=i;start<=j;start++)
        {
            sum+=p_nums[start];
        }
        return sum;*/
        /*if((j<=p_nums.size()-1)&&(i<=j))
        {
            if(i>=1)
                return p_nums[j]-p_nums[i-1];
            else if(i==0)
                return p_nums[j];
        }
        return 0;*/
        return p_nums[j+1]-p_nums[i];
    }
private:
    vector<int> p_nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */