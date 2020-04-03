class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //位运算
        // int a=0,b=0;
        // for(auto x:nums)
        // {
        //     b = (b ^ x) & ~a;
        //     a = (a ^ x) & ~b;
        // }
        // return b;
        //set数学方法
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

    // 这一题位运算的思路是K为奇数次的解法，实现是K=3的解法。K为偶数次的解法参考题目136。
    // 思路是通用的，按照位运算的解题思路，k=5的解法如下：
    // public class SingleNumberSolution137 {

    //     public int singleNumber(int[] nums) {
    //     int seenOnce = 0, seenTwice = 0, seenThird = 0,seenForth = 0;
    //     for (int num : nums) {
    //         seenOnce = ~seenTwice & ~seenThird & ~seenForth & (seenOnce ^ num);//若seenTwice,seenThird,seenForth不改变，改变seenOnce
    //         seenTwice = ~seenOnce & ~seenThird & ~seenForth & (seenTwice ^ num);//若seenOnce,seenThird,seenForth不改变，改变seenTwice
    //         seenThird = ~seenOnce & ~seenTwice & ~seenForth & (seenThird ^ num);
    //         seenForth = ~ seenOnce & ~seenTwice & ~seenThird & (seenForth ^ num);
    //     }
    //     return seenOnce;
    // }
    // }
    // 如此类推，k=2n+1的通用算法也呼之欲出了。
    }
};