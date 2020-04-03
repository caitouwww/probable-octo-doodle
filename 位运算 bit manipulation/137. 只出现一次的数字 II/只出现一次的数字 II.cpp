class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //λ����
        // int a=0,b=0;
        // for(auto x:nums)
        // {
        //     b = (b ^ x) & ~a;
        //     a = (a ^ x) & ~b;
        // }
        // return b;
        //set��ѧ����
        // set<long> a(nums.begin(),nums.end());
        // long suma=0;
        // for(auto x:nums)
        // {
        //     suma+=x;
        // }
        // long sums=0;
        // for(auto x:a)
        // {
        //     sums+=x;
        // }
        // return (3*sums-suma)/2;
        int seenOnce=0,seenTwice=0;
        for(auto x:nums)
        {
            seenOnce = ~seenTwice & (seenOnce ^ x);
            seenTwice = ~seenOnce & (seenTwice ^ x);
        }
        return seenOnce;

        // first appearance: 
        // add num to seen_once 
        // don't add to seen_twice because of presence in seen_once
            
        // second appearance: 
        // remove num from seen_once 
        // add num to seen_twice
            
        // third appearance: 
        // don't add to seen_once because of presence in seen_twice
        // remove num from seen_twice    

    // ��һ��λ�����˼·��KΪ�����εĽⷨ��ʵ����K=3�Ľⷨ��KΪż���εĽⷨ�ο���Ŀ136��
    // ˼·��ͨ�õģ�����λ����Ľ���˼·��k=5�Ľⷨ���£�
    // public class SingleNumberSolution137 {

    //     public int singleNumber(int[] nums) {
    //     int seenOnce = 0, seenTwice = 0, seenThird = 0,seenForth = 0;
    //     for (int num : nums) {
    //         seenOnce = ~seenTwice & ~seenThird & ~seenForth & (seenOnce ^ num);//��seenTwice,seenThird,seenForth���ı䣬�ı�seenOnce
    //         seenTwice = ~seenOnce & ~seenThird & ~seenForth & (seenTwice ^ num);//��seenOnce,seenThird,seenForth���ı䣬�ı�seenTwice
    //         seenThird = ~seenOnce & ~seenTwice & ~seenForth & (seenThird ^ num);
    //         seenForth = ~ seenOnce & ~seenTwice & ~seenThird & (seenForth ^ num);
    //     }
    //     return seenOnce;
    // }
    // }
    // ������ƣ�k=2n+1��ͨ���㷨Ҳ��֮�����ˡ�
    }
};